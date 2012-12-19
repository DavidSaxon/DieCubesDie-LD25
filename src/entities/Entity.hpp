#ifndef _ENTITY_H_
#	define _ENTITY_H_

#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Entity {
public:

    bool solid;
    unsigned hurtAmount;
    bool cube;
    bool dead;
    unsigned blood;
    unsigned blood1;
    unsigned blood2;
    unsigned blood3;
    unsigned blood4;
    unsigned x;
    unsigned y;
    int health;

	virtual void update() = 0;

	virtual void draw() const = 0;

    unsigned getX() const {

        return x;
    }

    unsigned getY() const {

        return y;
    }

    virtual bool canComplete() {

    }

protected:

};

#endif