#include "Spawn.hpp"

Spawn::Spawn(unsigned xPos, unsigned yPos, GLuint t) :
    tex(t) {

    x = xPos;
    y = yPos;
    solid = true; 
    hurtAmount = 0;
    cube = false;
    dead = false;
    blood = 0;
}

void Spawn::update() {
}

void Spawn::draw() const {
    
    glPushMatrix();

    glTranslatef(x, 0, -static_cast<int>(y));

    glBindTexture(GL_TEXTURE_2D, tex);
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0, 0.0); glVertex3f(0.0, 0.0, 1.0);
    glTexCoord3f(1.0, 0.0, 0.0); glVertex3f(1.0, 0.0, 1.0);
    glTexCoord3f(1.0, 1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
    glTexCoord3f(0.0, 1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glPopMatrix();
}