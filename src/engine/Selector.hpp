#ifndef _SELECTOR_H_
#   define _SELECTOR_H_

#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Selector {
public:

    int x;
    int y;
    int mx;
    int my;
    GLuint tex1;
    GLuint tex2;
    bool remove;
    int rx;
    int ry;

    //CONSTRUCTOR
    Selector(GLuint t1, GLuint t2);

    //FUNCTIONS
    void move(int x, int y);

    void draw();


};

#endif