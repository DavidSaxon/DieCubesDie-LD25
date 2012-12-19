#include "Engine.hpp"

//METHODS
/*Initialises the level*/
void Engine::levelInit() {

	frameLength = 17;
	startFrame = SDL_GetTicks();
	accumTime = 0;

	glClearColor(0.9, 0.9, 0.9, 1.0);
	cameraPos = Vector3(-10, -7.3, -21);
	cameraRot = Vector3(70, 0, 0);

	entities.clear();

	buildMaze();

	select = new Selector(selectionTex, removeTex);
	select->x = 9;
	select->y = 9;

	leftM = false;
	place = false;

	move = 0;

	dead = 0;
	escape = 0;

	deathTex = new GLuint[17];
	deathTex[0] =  rd1;
	deathTex[1] =  rd2;
	deathTex[2] =  rd3;
	deathTex[3] =  rd4;
	deathTex[4] =  bd1;
	deathTex[5] =  bd2;
	deathTex[6] =  bd3;
	deathTex[7] =  bd4;
	deathTex[8] =  d1;
	deathTex[9] =  d2;
	deathTex[10] = d3;
	deathTex[11] = d4;
	deathTex[12] = d5;
	deathTex[13] = d6;
	deathTex[14] = d7;
	deathTex[15] = d8;
	deathTex[16] = d9;

	initState = false;
}

/*updates the level*/
void Engine::levelUpdate() {

	long currentTime = SDL_GetTicks()-startFrame+accumTime;

	if (currentTime >= frameLength) {

		//decide whether to create another cube
		if (rand()%450 == 1) {

			bool generate = true;

			std::vector<Entity*>::const_iterator
				it = entities.begin(),
				ite = entities.end();
			for (; it != ite; ++it) {

				if ((*it)->cube && (*it)->getX() == 9 && (*it)->getY() == 0) {
					generate = false;
				}
			}

			if (generate) {
				if (rand()%2 == 0) {
					entities.push_back(new LeftWallFollower(
						9, 0, redCubeTex, redCube1Tex, redCube2Tex,
						redCube3Tex, redCube4Tex, &entities));
				}
				else {
					entities.push_back(new RightWallFollower(9, 0, blueCubeTex, 
						blueCube1Tex, blueCube2Tex, blueCube3Tex, blueCube4Tex,
						&entities));
				}
			}

		}

		//update the entities
		std::vector<Entity*>::iterator
			it = entities.begin(),
			ite = entities.end();
		for (; it != ite; ++it) {
			(*it)->update();
		}

		if (dx >= 30) {
			select->move(1, 0);
			SDL_WarpMouse(dWidth/2, dHeight/2);
		}
		else if (dx <= -30) {
			select->move(-1, 0);
			SDL_WarpMouse(dWidth/2, dHeight/2);
		}
		if (dy <= -30) {
			select->move(0, 1);
			SDL_WarpMouse(dWidth/2, dHeight/2);
		}
		else if (dy >= 30) {
			select->move(0, -1);
			SDL_WarpMouse(dWidth/2, dHeight/2);
		}

		if (leftM && !place) {

			it = entities.begin();
			ite = entities.end();
			for (; it != ite; ++it) {
				if ((*it)->solid && (*it)->getX() == select->x &&
					(*it)->getY() == select->y) {
					place = true;
					select->remove = true;
					select->rx = select->x;
					select->ry = select->y;
					move = (*it);
					break;
				}
			}
			leftM = false;
		}


		bool valid = false;
		if (leftM && place) {

			valid = true;

			unsigned ox = move->x;
			unsigned oy = move->y; 

			it = entities.begin();
			ite = entities.end();
			for (; it != ite; ++it) {

				if(((*it)->solid || (*it)->cube || (*it)->hurtAmount > 0) &&
					((*it)->getX() == select->x && (*it)->getY() == select->y)) {
					valid = false;
					break;
				}
			}

			move->x = select->x;
			move->y = select->y;

			it = entities.begin();
			ite = entities.end();
			for (; it != ite; ++it) {

				if ((*it)->cube && !(*it)->canComplete()) {
					valid = false;
					break;
				}
			}

			move->x = ox;
			move->y = oy;

			leftM = false;
		}

		if (valid) {
			place = false;
			select->remove = false;
			move->x = select->x;
			move->y = select->y;
		}

		//remove completed/dead entities
		bool kill = false;
		bool dieded = false;
		it = entities.begin();
		ite = entities.end();
		for (; it != ite; ++it) {
			if ((*it)->cube && (*it)->getX() == 9 && (*it)->getY() == 19) {
				kill = true;
				++escape;
				break;
			}
			else if ((*it)->cube && (*it)->health <= 0) {
				kill = true;
				dieded = true;
				++dead;
				break;
			}
			else if ((*it)->dead) {
				kill = true;
				break;
			}
		}

		if (kill) {
			if (dieded) {
				entities.push_back(new Death((*it)->getX(),
					(*it)->getY(), deathTex));
			}
			entities.erase(it);
		}

		accumTime = currentTime-frameLength; //find the accumulated time
		startFrame = SDL_GetTicks(); //set the start time of the new frame
	}


	//draw the entities
	std::vector<Entity*>::const_iterator
		it = entities.begin(),
		ite = entities.end();
	for (; it != ite; ++it) {
		(*it)->draw();
	}


	//draw the background
    glBindTexture(GL_TEXTURE_2D, backTex);
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-21.0, -10.0, 2.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(41.0, -10.0, 2.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(41.0, -10.0, -30.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-21.0, -10.0, -30.0);
    glEnd();

    //draw the selector
    select->draw();


    //draw score
    if (dead == 0) {
    	glBindTexture(GL_TEXTURE_2D, n0);
	}
	else if (dead == 1) {
    	glBindTexture(GL_TEXTURE_2D, n1);
	}
	else if (dead == 2) {
    	glBindTexture(GL_TEXTURE_2D, n2);
	}
	else if (dead == 3) {
    	glBindTexture(GL_TEXTURE_2D, n3);
	}
	else if (dead == 4) {
    	glBindTexture(GL_TEXTURE_2D, n4);
	}
	else if (dead == 5) {
    	glBindTexture(GL_TEXTURE_2D, n5);
	}
	else if (dead == 6) {
    	glBindTexture(GL_TEXTURE_2D, n6);
	}
	else if (dead == 7) {
    	glBindTexture(GL_TEXTURE_2D, n7);
	}
	else if (dead == 8) {
    	glBindTexture(GL_TEXTURE_2D, n8);
	}
	else if (dead == 9) {
    	glBindTexture(GL_TEXTURE_2D, n9);
	}
	else {
    	glBindTexture(GL_TEXTURE_2D, n1);
	}

    glColor4f(1, 1, 1, 1);

    glPushMatrix();

    glTranslatef(-8.8, 0, -27.35);

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, -9, 1.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, -9, 1.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, -9, 0.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, -9, 0.0);
    glEnd();

    glPopMatrix();

    if (dead > 9) {

    	if (dead == 10) {
	    	glBindTexture(GL_TEXTURE_2D, n0);
    	}
    	else if (dead == 11) {
	    	glBindTexture(GL_TEXTURE_2D, n1);
    	}
    	else if (dead == 12) {
	    	glBindTexture(GL_TEXTURE_2D, n2);
    	}
    	else {
    		glBindTexture(GL_TEXTURE_2D, n3);
    	}

	    glColor4f(1, 1, 1, 1);

	    glPushMatrix();

	    glTranslatef(-7.8, 0, -27.35);

	    glBegin(GL_QUADS);
	    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, -9, 1.0);
	    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, -9, 1.0);
	    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, -9, 0.0);
	    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, -9, 0.0);
	    glEnd();

	    glPopMatrix();
    }

        //draw score
    if (escape == 0) {
    	glBindTexture(GL_TEXTURE_2D, n0);
	}
	else if (escape == 1) {
    	glBindTexture(GL_TEXTURE_2D, n1);
	}
	else if (escape == 2) {
    	glBindTexture(GL_TEXTURE_2D, n2);
	}
	else if (escape == 3) {
    	glBindTexture(GL_TEXTURE_2D, n3);
	}
	else if (escape == 4) {
    	glBindTexture(GL_TEXTURE_2D, n4);
	}
	else if (escape == 5) {
    	glBindTexture(GL_TEXTURE_2D, n5);
	}
	else if (escape == 6) {
    	glBindTexture(GL_TEXTURE_2D, n6);
	}
	else if (escape == 7) {
    	glBindTexture(GL_TEXTURE_2D, n7);
	}
	else if (escape == 8) {
    	glBindTexture(GL_TEXTURE_2D, n8);
	}
	else if (escape == 9) {
    	glBindTexture(GL_TEXTURE_2D, n9);
	}
	else {
    	glBindTexture(GL_TEXTURE_2D, n1);
	}

    glColor4f(1, 1, 1, 1);

    glPushMatrix();

    glTranslatef(-10.8, 0, -25.85);

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, -9, 1.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, -9, 1.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, -9, 0.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, -9, 0.0);
    glEnd();

    glPopMatrix();

    if (escape > 9) {

    	if (escape == 10) {
	    	glBindTexture(GL_TEXTURE_2D, n0);
    	}
    	else if (escape == 11) {
	    	glBindTexture(GL_TEXTURE_2D, n1);
    	}
    	else if (escape == 12) {
	    	glBindTexture(GL_TEXTURE_2D, n2);
    	}
    	else {
    		glBindTexture(GL_TEXTURE_2D, n3);
    	}

	    glColor4f(1, 1, 1, 1);

	    glPushMatrix();

	    glTranslatef(-9.8, 0, -25.85);

	    glBegin(GL_QUADS);
	    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, -9, 1.0);
	    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, -9, 1.0);
	    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, -9, 0.0);
	    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, -9, 0.0);
	    glEnd();

	    glPopMatrix();
    }

    //draw camera blood;
    if (dead > 0 || escape >= 13) {

    	glLoadIdentity();

    	glColor4f(1, 0, 1, 1);

    	if (escape >= 13) {
    		glBindTexture(GL_TEXTURE_2D, lose);
    	}
    	else if (dead == 1) {
    		glBindTexture(GL_TEXTURE_2D, b1);
    	}
		else if (dead == 2) {
    		glBindTexture(GL_TEXTURE_2D, b2);
    	}
    	else if (dead == 3) {
    		glBindTexture(GL_TEXTURE_2D, b3);
    	}
    	else if (dead == 4) {
    		glBindTexture(GL_TEXTURE_2D, b4);
    	}
    	else if (dead == 5) {
    		glBindTexture(GL_TEXTURE_2D, b5);
    	}
    	else if (dead == 6) {
    		glBindTexture(GL_TEXTURE_2D, b6);
    	}
    	else if (dead == 7) {
    		glBindTexture(GL_TEXTURE_2D, b7);
    	}
    	else if (dead == 8) {
    		glBindTexture(GL_TEXTURE_2D, b8);
    	}
    	else if (dead == 9) {
    		glBindTexture(GL_TEXTURE_2D, b9);
    	}
    	else if (dead == 10) {
    		glBindTexture(GL_TEXTURE_2D, b10);
    	}
    	else if (dead == 11) {
    		glBindTexture(GL_TEXTURE_2D, b11);
    	}
    	else if (dead == 12) {
    		glBindTexture(GL_TEXTURE_2D, b12);
    	}
    	else if (dead >= 13) {
    		glBindTexture(GL_TEXTURE_2D, win);
		}

    	glBegin(GL_QUADS);
	    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-2.21, -1.25, -3.0);
    	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(2.21, -1.25, -3.0);
    	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(2.21, 1.25, -3.0);
    	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-2.21, 1.25, -3.0);
    	glEnd();


    }

}

void Engine::buildMaze() {

	entities.push_back(new LeftWallFollower(
		9, 0, redCubeTex, redCube1Tex, redCube2Tex,
		redCube3Tex, redCube4Tex, &entities));

	for (unsigned i = 0; i < LEVEL_HEIGHT; ++i) {
		for (unsigned j = 0; j < LEVEL_WIDTH; ++j) {
			if (i != 0 && i != 19) {
				entities.push_back(new Floor(j, i, floorTex, floor1Tex,
					floor2Tex, floor3Tex, floor4Tex));
			}
		}
	}

	entities.push_back(new Spawn(9, 0, spawnTex));
	entities.push_back(new Exit(9, 19, exitTex));

	entities.push_back(new Spike(9, 16, spikeBottomCleanTex,
		spikeBottomBloodTex, spikeTopCleanTex, spikeTopBloodTex));
	entities.push_back(new Spike(4, 10, spikeBottomCleanTex,
		spikeBottomBloodTex, spikeTopCleanTex, spikeTopBloodTex));
	entities.push_back(new Spike(17, 10, spikeBottomCleanTex,
		spikeBottomBloodTex, spikeTopCleanTex, spikeTopBloodTex));
	entities.push_back(new Spike(9, 4, spikeBottomCleanTex,
		spikeBottomBloodTex, spikeTopCleanTex, spikeTopBloodTex));


	for (unsigned i = 0; i < LEVEL_HEIGHT; ++i) {
		for (unsigned j = 0; j < LEVEL_WIDTH; ++j) {

			if (j == 0 || j == LEVEL_WIDTH-1 ||
				i == 0 || i == LEVEL_HEIGHT-1) {
				if (i != 9) {
					entities.push_back(new Wall(i, j, wallTex, wall1Tex, 
						wall2Tex, wall3Tex, wall4Tex, true));
				}
			}
		}
	}

	for (unsigned i = 5; i < 15; ++i) {
		for(unsigned j = 5; j < 15; ++j) {
			entities.push_back(new Wall(i, j, wallTex, wall1Tex, wall2Tex,
				wall3Tex, wall4Tex, false));
		}
	}
}