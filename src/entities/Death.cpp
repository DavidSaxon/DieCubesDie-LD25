#include "Death.hpp"

Death::Death(unsigned xPos, unsigned yPos, GLuint* t) {

    x = xPos;
    y = yPos;
    tex = t;
    ani = 8;
    counter = 0;

    solid = false;
    hurtAmount = 0;
    cube = false;
    dead = false;
    health = 0;
    blood = 0;
}

void Death::update() {

    if (ani == 80) {
        dead = true;
    }

    if (counter == 2) {
        ++ani;
        counter = 0;
    }
    else {
        ++counter;
    }

}

void Death::draw() const {

    glPushMatrix();

    glTranslatef(x, 0, -static_cast<int>(y));


    if (ani < 17) {
        glBindTexture(GL_TEXTURE_2D, tex[ani]);
    }
    else {
        glBindTexture(GL_TEXTURE_2D, tex[16]);
    }

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0, 0.0, -0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1, 0.0, -0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1, 1, -0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0, 1, -0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0, 0.0, -0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(-0, 0.0, 1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(-0, 1, 1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0, 1, -0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0, 0.0, -0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(-0, 1, -0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(-0, 1, 1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0, 0.0, 1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1, 0.0, -0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1, 0.0, 1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1, 1, -0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1, 0.0, -0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1, 1, -0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1, 0.0, 1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0, 0.0, 1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1, 0.0, 1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0, 1, 1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0, 1, 1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1, 1, 1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1, 1, -0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0, 1, -0);
    glEnd();

    glPopMatrix();

}