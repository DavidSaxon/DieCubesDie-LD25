/******************\
| DESRICPTION HERE |
\******************/
#ifndef _ENGINE_H_
#   define _ENGINE_H_

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <png.h>

#include "Event.hpp"
#include "Define.hpp"
#include "../exceptions/DisplayException.hpp"
#include "../entities/Entity.hpp"
#include "Selector.hpp"

using namespace std;

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
    //The current state of the game
    State gameState;
    //True if the the game state needs to be initialised
    bool initState;
    //The position of the camera
    Vector3 cameraPos;
    //the rotation of the camera
    Vector3 cameraRot;

    //the level
    std::vector<Entity*> entities;

    //fps management
    int frameLength; //the length of a frame
    long startFrame; //the time the frame started
    long accumTime; //the time accumulated from the last frame

    //METHODS
    /*Initialise SDL*/
    void initSDL();

    /*Initialise openGL*/
    void initOpenGL();

//LEVEL
public:

    //METHODS
    /*Initialises the level*/
    void levelInit();

    /*updates the level*/
    void levelUpdate();

private:

    void buildMaze();

    Selector* select;
    int dx;
    int dy;
    bool leftM;
    bool place;
    Entity* move;
    int dead;
    int escape;

//RESOURCES
private:

    //VARIABLES
    GLubyte* img;

    GLuint floorTex;
    GLuint floor1Tex;
    GLuint floor2Tex;
    GLuint floor3Tex;
    GLuint floor4Tex;
    GLuint redCubeTex;
    GLuint redCube1Tex;
    GLuint redCube2Tex;
    GLuint redCube3Tex;
    GLuint redCube4Tex;
    GLuint blueCubeTex;
    GLuint blueCube1Tex;
    GLuint blueCube2Tex;
    GLuint blueCube3Tex;
    GLuint blueCube4Tex;
    GLuint wallTex;
    GLuint wall1Tex;
    GLuint wall2Tex;
    GLuint wall3Tex;
    GLuint wall4Tex;
    GLuint spawnTex;
    GLuint exitTex;
    GLuint backTex;
    GLuint spikeBottomCleanTex;
    GLuint spikeBottomBloodTex;
    GLuint spikeTopCleanTex;
    GLuint spikeTopBloodTex;
    GLuint selectionTex;
    GLuint removeTex;
    GLuint b1;
    GLuint b2;
    GLuint b3;
    GLuint b4;
    GLuint b5;
    GLuint b6;
    GLuint b7;
    GLuint b8;
    GLuint b9;
    GLuint b10;
    GLuint b11;
    GLuint b12;
    GLuint b13;
    GLuint rd1;
    GLuint rd2;
    GLuint rd3;
    GLuint rd4;
    GLuint bd1;
    GLuint bd2;
    GLuint bd3;
    GLuint bd4;
    GLuint d1;
    GLuint d2;
    GLuint d3;
    GLuint d4;
    GLuint d5;
    GLuint d6;
    GLuint d7;
    GLuint d8;
    GLuint d9;
    GLuint n0;
    GLuint n1;
    GLuint n2;
    GLuint n3;
    GLuint n4;
    GLuint n5;
    GLuint n6;
    GLuint n7;
    GLuint n8;
    GLuint n9;
    GLuint win;
    GLuint lose;

    GLuint * deathTex;

    //FUNCTIONS
    void loadTextures();

    bool loadImage(char *name, int &outWidth, int &outHeight,
        bool &outHasAlpha, GLubyte **outData);

//EVENT
public:

    //FUNCTIONS
    /*Handles events*/
    void onEvent(SDL_Event *event);

    /*When the window close button is pressed*/
    void onExit();

    /*When a key is pressed */
    void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

    void onMouseMove(int mX, int mY, int relX, int relY,
    bool left,bool right,bool middle);

    void onLButtonUp(int mX, int mY);

};

#endif