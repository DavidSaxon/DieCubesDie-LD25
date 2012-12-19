#include "Engine.hpp"

/*Handles events*/
void Engine::onEvent(SDL_Event *event) {

    Event::onEvent(event); //gets and stores the current event
}

/*When the window close button is pressed*/
void Engine::onExit() {

    running = false; //exit the game
}

/*When a key is pressed */
void Engine::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

    /*exit the game, REMOVE THIS*/
    if (sym == SDLK_ESCAPE) {
        running = false;
    }
    if (sym == SDLK_r) {
        initState = true;
    }
    if (sym == SDLK_q) {
        running = false;
    }
}

void Engine::onMouseMove(int mX, int mY, int relX, int relY,
    bool left,bool right,bool middle) {
    dx = mX-(dWidth/2);
    dy = mY-(dHeight/2);
}

void Engine::onLButtonUp(int mX, int mY) {

    leftM = true;
}