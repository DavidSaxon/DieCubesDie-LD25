#include "Floor.hpp"

//CONSTRUCTOR
Floor::Floor(unsigned xPos, unsigned yPos, GLuint t1, GLuint t2,
	GLuint t3, GLuint t4, GLuint t5) :
	tex1(t1),
	tex2(t2),
	tex3(t3),
	tex4(t4),
	tex5(t5) {

	x = xPos;
	y = yPos;
	solid = false;
	hurtAmount = 0;
	cube = false;
	dead = false;
	blood = 0;
}

void Floor::update() {
}

void Floor::draw() const {

	glPushMatrix();

	glTranslatef(x, 0, -static_cast<int>(y));

	if (blood == 0) {
		glBindTexture(GL_TEXTURE_2D, tex1);
	}
	else if (blood == 1) {
		glBindTexture(GL_TEXTURE_2D, tex2);
	}
	else if (blood == 2) {
		glBindTexture(GL_TEXTURE_2D, tex3);
	}
	else if (blood == 3) {
		glBindTexture(GL_TEXTURE_2D, tex4);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, tex5);
	}

	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();
}