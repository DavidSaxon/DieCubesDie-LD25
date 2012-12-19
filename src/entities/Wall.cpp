#include "Wall.hpp"

Wall::Wall(unsigned xPos, unsigned yPos, GLuint t1, GLuint t2,
    GLuint t3, GLuint t4, GLuint t5, bool o) :
	tex1(t1),
	tex2(t2),
	tex3(t3),
	tex4(t4),
	tex5(t5),
	outside(o) {

	x = xPos;
	y = yPos;
	solid = true;
	dead = false;
	hurtAmount = 0;		
	cube = false;
	blood = 0;
	blood1 = 0;
	blood2 = 0;
	blood3 = 0;
	blood4 = 0;
}

void Wall::update() {
}

void Wall::draw() const {

	glPushMatrix();

	glTranslatef(x, 0, -static_cast<int>(y));

	glColor4f(1, 1, 1, 1);

	glPushMatrix();

	glTranslatef(0, 1.0, 1.0);

	glRotatef(90, 1, 0, 0);

	if (blood1 == 0) {
		glBindTexture(GL_TEXTURE_2D, tex1);
	}
	else if (blood1 == 1) {
		glBindTexture(GL_TEXTURE_2D, tex2);
	}
	else if (blood1 == 2) {
		glBindTexture(GL_TEXTURE_2D, tex3);
	}
	else if (blood1 == 3) {
		glBindTexture(GL_TEXTURE_2D, tex4);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, tex5);
	}

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, tex1);

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

	if (blood2 == 0) {
		glBindTexture(GL_TEXTURE_2D, tex1);
	}
	else if (blood2 == 1) {
		glBindTexture(GL_TEXTURE_2D, tex2);
	}
	else if (blood2 == 2) {
		glBindTexture(GL_TEXTURE_2D, tex3);
	}
	else if (blood2 == 3) {
		glBindTexture(GL_TEXTURE_2D, tex4);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, tex5);
	}

	glTranslatef(1, 1.0, 0.0);

	glRotatef(-90, 0, 0, 1);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	if (blood4 == 0) {
		glBindTexture(GL_TEXTURE_2D, tex1);
	}
	else if (blood4 == 1) {
		glBindTexture(GL_TEXTURE_2D, tex2);
	}
	else if (blood4 == 2) {
		glBindTexture(GL_TEXTURE_2D, tex3);
	}
	else if (blood4 == 3) {
		glBindTexture(GL_TEXTURE_2D, tex4);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, tex5);
	}

	glTranslatef(0, 0.0, 0.0);

	glRotatef(90, 0, 0, 1);

	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();

    glPopMatrix();
}