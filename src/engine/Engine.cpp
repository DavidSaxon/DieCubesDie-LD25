#include "Engine.hpp" 

//CONSTRUCTOR
/*Creates a new unitialised engine*/
Engine::Engine() :
    running (true) {
}

//DESTRUCTOR
Engine::~Engine() {

    delete img;
    delete deathTex;
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

    //load textures
    loadTextures();

    //set the game state
    gameState = LEVEL;
    initState = true;

    //set the camera position
    cameraPos = Vector3(0, 0, -1);
    cameraRot = Vector3(0, 0, 0);

    dx = 0;
    dy = 0;

    SDL_ShowCursor(false);

    srand(time(0));
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

        if (initState) {

            switch(gameState) {
                case TITLE:
                    break;
                case LEVEL:
                    levelInit();
                    break;
            }
        }

        //draw a cube for testing
        glLoadIdentity();

        //translate to the camera position
        glTranslatef(cameraPos.x, cameraPos.y, cameraPos.z);
        //rotate the camera
        glRotatef(cameraRot.x, 1, 0, 0);
        glRotatef(cameraRot.y, 0, 1, 0);
        glRotatef(cameraRot.z, 0, 0, 1);

        switch(gameState) {

            case TITLE:
                break;
            case LEVEL:
                levelUpdate();
                break;
        }

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

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glClearColor(0, 0, 0, 1);
    glClearDepth(1000.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, static_cast<float>(dWidth)/static_cast<float>(dHeight),
        0.001, 200.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    glEnable(GL_TEXTURE_2D);
}