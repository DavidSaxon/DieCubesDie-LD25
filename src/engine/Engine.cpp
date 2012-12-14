#include "Engine.hpp" 

//CONSTRUCTOR
/*Creates a new unitialised engine*/
Engine::Engine() :
    running (true) {


}

//DESTRUCTOR
Engine::~Engine() {
}

//PUBLIC METHODS
/*Initialises the engine*/
void Engine::init() {

    //intiliase sdl
    initSDL();

    //open the window
    const SDL_VideoInfo *videoInfo = SDL_GetVideoInfo(); //get the video info
    //sets the window flags
    int flags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER
        | SDL_HWPALETTE | SDL_FULLSCREEN;
    //check if hardware surfaces can be enabled
    if(videoInfo->hw_available) {
        flags |= SDL_HWSURFACE;
    }
    else {
        flags |= SDL_SWSURFACE;
    }
    //check to see if hardware supports blitting
    if(videoInfo->blit_hw) {
        flags |= SDL_HWACCEL;
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //sets up the video mode
    if ((display = SDL_SetVideoMode(0, 0, 32, flags)) == 0) {
        throw WindowException("Main game window failed to open");
    }

    //get the width and height of the display
    dWidth = display->w;
    dHeight = display->h;

    //initialise opengl
    initOpenGL();

}

/*Starts the main game loop*/
void Engine::execute() {

    //the event
    SDL_Event event;

    //the main loop
    while (running) {

        //poll events
        while (SDL_PollEvent(&event)) onEvent(&event);

        //clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //swap the buffers
        SDL_GL_SwapBuffers();
    }

}

/*Closes the engine and cleans up memory*/
void Engine::close() {

}

//PRIVATE METHODS
/*Initialise sdl*/
void Engine::initSDL() {

    if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO) < 0) {
        throw SDLException("SDL initialisation error");
    }
}

/*Initialise openGL*/
void Engine::initOpenGL() {

    //Standard initialisation for 2D openGl

    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(0, NATURAL_RESO_X, NATURAL_RESO_Y, 0, 0, 1);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glEnable(GL_TEXTURE_2D);
}