#include "Spike.hpp"

Spike::Spike(unsigned xPos, unsigned yPos, GLuint t1, GLuint t2,
	GLuint t3, GLuint t4) :
	tex1(t1),
	tex2(t2),
	tex3(t3),
	tex4(t4) {

	x = xPos;
	y = yPos;
	solid = false;
	hurtAmount = 1;
	cube = false;
	dead = false;
	blood = 0;
}

void Spike::update() {

}

void Spike::draw() const {

	glPushMatrix();

	glTranslatef(x, 0, -static_cast<int>(y));

	if (blood == 0) {
		glBindTexture(GL_TEXTURE_2D, tex1);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, tex2);
	}

	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.1, 1.0);
	glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.1, 1.0);
	glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.1, 0.0);
	glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.1, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();


	glTranslatef(x, 0, -static_cast<int>(y));	
	
	if (blood == 0) {
		glBindTexture(GL_TEXTURE_2D, tex3);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, tex4);
	}
	

	glColor4f(1, 1, 1, 1);

	for (float j = 0; j < 1.0; j += 0.2) {
		for (float i = 0; i < 1.0; i += 0.2) {

			glBegin(GL_TRIANGLE_FAN);
			glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(i, 0.1, j+0.2);
			glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(i+0.2, 0.1, j+0.2);
			glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(i+0.1, 0.25,  j);
			glEnd();
		}
	}

	glPopMatrix();

}