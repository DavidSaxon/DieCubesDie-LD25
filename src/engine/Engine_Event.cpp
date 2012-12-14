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
    if (sym == SDLK_F7) {
        running = false;
    }
}