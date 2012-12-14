/******************\
| DESRICPTION HERE |
\******************/
#ifndef _ENGINE_H_
#   define _ENGINE_H_

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Event.hpp"
#include "Define.hpp"
#include "../exceptions/DisplayException.hpp"

class Engine : public Event {
public:

    //CONSTRUCTOR
    /*Creates a new unitialised engine*/
    Engine();

    //DESTRUCTOR
    ~Engine();

    //METHODS
    /*Initialises the engine*/
    void init();

    /*Starts the main game loop*/
    void execute();

    /*Closes the engine and cleans up memory*/
    void close();

private:

    //VARIABLES
    //true while the game is running
    bool running;
    //the window
    SDL_Surface *display;
    //the width and height of the window
    unsigned dWidth;
    unsigned dHeight;

    //METHODS
    /*Initialise SDL*/
    void initSDL();

    /*Initialise openGL*/
    void initOpenGL();

//EVENT
public:

    //FUNCTIONS
    /*Handles events*/
    void onEvent(SDL_Event *event);

    /*When the window close button is pressed*/
    void onExit();

    /*When a key is pressed */
    void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

};

#endif