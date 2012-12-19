#include "LeftWallFollower.hpp"

//CONSTRUCTOR
LeftWallFollower::LeftWallFollower(unsigned xPos, unsigned yPos,
    GLuint t1, GLuint t2, GLuint t3, GLuint t4, GLuint t5,
    std::vector<Entity*>* e) :
	tex1(t1),
	tex2(t2),
	tex3(t3),
	tex4(t4),
	tex5(t5),
	entities(e),
	moveCounter(0),
	rotate(0) {

	x = xPos;
	y = yPos;
	solid = false;
	animate = true;
	onLeft = true;
	inFront = false;
	dir = UP;
	move = true;
	hurtAmount = 0;
	cube = true;
	dead = false;
	health = 5;
	blood = 0;
}

//METHODS
void LeftWallFollower::update() {

	if (moveCounter == 14) {

		if (move) {
			if (dir == UP) {
				++y;
			}
			else if (dir == LEFT) {
				--x;
			}
			else if (dir == DOWN) {
				--y;
			}
			else if (dir == RIGHT) {
				++x;
			}
		}


        //check if hurt
        std::vector<Entity*>::const_iterator
            it = entities->begin(),
            ite = entities->end();
        for (; it != ite; ++it) {

            if ((*it)->hurtAmount != 0 && (*it)->getX() == x &&
                (*it)->getY() == y) {
                --health;
                (*it)->blood = 1;
            }
        }

        if (health < 5) {
            //smear blood
            it = entities->begin();
            ite = entities->end();
            for (;it != ite; ++it) {

                if ((*it)->solid) {
                    if ((*it)->getX() == x && (*it)->getY() == y+1) {
                        ++(*it)->blood1;
                    }
                    else if ((*it)->getX() == x && (*it)->getY() == y-1) {
                        ++(*it)->blood3;
                    }
                    else if ((*it)->getX() == x+1 && (*it)->getY() == y) {
                        ++(*it)->blood4;
                    }
                    else if ((*it)->getX() == x-1 && (*it)->getY() == y) {
                        ++(*it)->blood2;
                    }
                }
                else if ((*it)->getX() == x && (*it)->getY() == y) {
                    ++(*it)->blood;
                }
            }
        }

		onLeft = false;
		it = entities->begin();
		ite = entities->end();
		for (; it != ite; ++it) {

			if (dir == UP) {
				if ((*it)->solid && (*it)->getX() == x-1 &&
					(*it)->getY() == y) {
					onLeft = true;
				}
			}
			else if (dir == LEFT) {
				if ((*it)->solid && (*it)->getY() == y-1 &&
					(*it)->getX() == x) {
					onLeft = true;
				}
			}
			else if (dir == DOWN) {
				if ((*it)->solid && (*it)->getX() == x+1 &&
					(*it)->getY() == y) {
					onLeft = true;
				}
			}
			else if (dir == RIGHT) {
				if ((*it)->solid && (*it)->getY() == y+1 &&
					(*it)->getX() == x) {
					onLeft = true;
				}
			}
		}

		inFront = false;
		move = true;
		animate = true;
		if(onLeft) {

			it = entities->begin();
			ite = entities->end();
			for (; it != ite; ++it) {

				if (dir == UP) {
					if ((*it)->solid && (*it)->getX() == x &&
						(*it)->getY() == y+1) {
						inFront = true;
					}
				}
				else if (dir == LEFT) {
					if ((*it)->solid && (*it)->getY() == y &&
						(*it)->getX() == x-1) {
						inFront = true;
					}
				}
				else if (dir == DOWN) {
					if ((*it)->solid && (*it)->getX() == x &&
						(*it)->getY() == y-1) {
						inFront = true;
					}
				}
				else if (dir == RIGHT) {
					if ((*it)->solid && (*it)->getY() == y &&
						(*it)->getX() == x+1) {
						inFront = true;
					}
				}
			}

			if (inFront) {
				dir = static_cast<Direction>((dir+1)%4);
				animate = false;
				move = false;
			}
		}
		else {

			animate = true;

			if (dir == UP) {
				dir = LEFT;
				onLeft = true;
			}
			else if (dir == LEFT) {
				dir = DOWN;
				onLeft = true;
			}
			else if (dir == DOWN) {
				dir = RIGHT;
				onLeft = true;
			}
			else if (dir == RIGHT) {
				dir = UP;
				onLeft = true;
			}
		}

		moveCounter = 0;
		rotate = 0;
	}
	else {
		++moveCounter;
		if (animate) {
			rotate += 6;
		}
	}
}

bool LeftWallFollower::canComplete() {

	unsigned tx = x;
	unsigned ty = y;
	Direction td = dir;
	tonLeft = onLeft;
	tinFront = inFront;
	tmove = move;

	bool valid = false;

	for (unsigned i = 0; i < 1600; ++i) {

		if (tmove) {
			if (td == UP) {
				++ty;
			}
			else if (td == LEFT) {
				--tx;
			}
			else if (td == DOWN) {
				--ty;
			}
			else if (td == RIGHT) {
				++tx;
			}
		}

		if (tx == 9 && ty == 19) {
			valid = true;
			break;
		}

		tonLeft = false;
		std::vector<Entity*>::const_iterator
			it = entities->begin(),
			ite = entities->end();
		for (; it != ite; ++it) {

			if (td == UP) {
				if ((*it)->solid && (*it)->getX() == tx-1 &&
					(*it)->getY() == ty) {
					tonLeft = true;
				}
			}
			else if (td == LEFT) {
				if ((*it)->solid && (*it)->getY() == ty-1 &&
					(*it)->getX() == tx) {
					tonLeft = true;
				}
			}
			else if (td == DOWN) {
				if ((*it)->solid && (*it)->getX() == tx+1 &&
					(*it)->getY() == ty) {
					tonLeft = true;
				}
			}
			else if (td == RIGHT) {
				if ((*it)->solid && (*it)->getY() == ty+1 &&
					(*it)->getX() == tx) {
					tonLeft = true;
				}
			}
		}

		tinFront = false;
		tmove = true;
		if(tonLeft) {

			it = entities->begin();
			ite = entities->end();
			for (; it != ite; ++it) {

				if (td == UP) {
					if ((*it)->solid && (*it)->getX() == tx &&
						(*it)->getY() == ty+1) {
						tinFront = true;
					}
				}
				else if (td == LEFT) {
					if ((*it)->solid && (*it)->getY() == ty &&
						(*it)->getX() == tx-1) {
						tinFront = true;
					}
				}
				else if (td == DOWN) {
					if ((*it)->solid && (*it)->getX() == tx &&
						(*it)->getY() == ty-1) {
						tinFront = true;
					}
				}
				else if (td == RIGHT) {
					if ((*it)->solid && (*it)->getY() == ty &&
						(*it)->getX() == tx+1) {
						tinFront = true;
					}
				}
			}

			if (tinFront) {
				td = static_cast<Direction>((td+1)%4);
				tmove = false;
			}
		}
		else {

			if (td == UP) {
				td = LEFT;
				tonLeft = true;
			}
			else if (td == LEFT) {
				td = DOWN;
				tonLeft = true;
			}
			else if (td == DOWN) {
				td = RIGHT;
				tonLeft = true;
			}
			else if (td == RIGHT) {
				td = UP;
				tonLeft = true;
			}
		}
	}

	return valid;
}

void LeftWallFollower::draw() const {

	glPushMatrix();

	glTranslatef(x, 0, -static_cast<int>(y));

	if (animate) {
		if (dir == UP) {
			glRotatef(-rotate, 1, 0, 0);
		}
		else if (dir == LEFT) {
			glRotatef(rotate, 0, 0, 1);
		}
		else if (dir == DOWN) {
			glTranslatef(0, 0, 1);
			glRotatef(rotate, 1, 0, 0);
			glTranslatef(0, 0, -1);
		}
		else if (dir == RIGHT) {
			glTranslatef(1, 0, 0);
			glRotatef(-rotate, 0, 0, 1);
			glTranslatef(-1, 0, 0);
		}
	}

    if (health == 5) {
        glBindTexture(GL_TEXTURE_2D, tex1);
    }
    else if (health == 4) {
        glBindTexture(GL_TEXTURE_2D, tex2);
    }
    else if (health == 3) {
        glBindTexture(GL_TEXTURE_2D, tex3);
    }
    else if (health == 2) {
        glBindTexture(GL_TEXTURE_2D, tex4);
    }
    else {
        glBindTexture(GL_TEXTURE_2D, tex5);
    }
    
    glColor4f(1, 1, 1, 1);


	glPushMatrix();

	glTranslatef(0, 1.0, 1.0);

	glRotatef(90, 1, 0, 0);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 1.0, 1.0);

	glRotatef(90, 0, 1, 0);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(1, 1.0, 0.0);

	glRotatef(-90, 0, 0, 1);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(1, 1.0, 0.0);

bool canComplete();
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);


	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(1, 1.0, 0.0);

	glRotatef(-90, 0, 0, 1);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(0.0, -1.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(0, 1.0, 1.0);

	glRotatef(90, 0, 1, 0);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(0.0, -1.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glEnd();

	glPopMatrix();

    glPopMatrix();
}