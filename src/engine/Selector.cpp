#include "Selector.hpp"

//CONSTRUCTOR
Selector::Selector(GLuint t1, GLuint t2) :
    tex1(t1),
    tex2(t2),
    x(0),
    y(0) {

    remove = false;
    rx = 0;
    ry = 0;
}

//FUNCTIONS
void Selector::move(int _x, int _y) {

    if (x+_x > 0 && x+_x < 19) {
        x += _x;
    }

    if (y+_y > 0 && y+_y < 19) {
        y += _y;
    }
}

void Selector::draw() {

    glPushMatrix();

    glTranslatef(x, 0, -y);

    glBindTexture(GL_TEXTURE_2D, tex1);

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, -0.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 0.0, -0.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, -0.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, 1.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, -0.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 0.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.1, 0.0, -0.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 0.0, 1.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.1, 0.0, -0.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.1, 0.0, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, 1.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 0.0, 1.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
    glEnd();

    glPopMatrix();


    if (remove) {

        glPushMatrix();

        glTranslatef(rx, 0, -ry);

        glBindTexture(GL_TEXTURE_2D, tex2);

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, -0.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 0.0, -0.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
        glEnd();

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, -0.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, 1.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
        glEnd();

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, -0.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 0.0, 1.1);
        glEnd();

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.1, 0.0, -0.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 0.0, 1.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
        glEnd();

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(1.1, 0.0, -0.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(1.1, 0.0, 1.1);
        glEnd();

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 0.0, 1.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 0.0, 1.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
        glEnd();

        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(-0.1, 1.1, 1.1);
        glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.1, 1.1, 1.1);
        glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.1, 1.1, -0.1);
        glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(-0.1, 1.1, -0.1);
        glEnd();

        glPopMatrix();

    }
}