#pragma once
#include <SDL2/SDL.h>

class Simulator
{
public:
    Simulator();
    int onExecute();

    bool onInit();
    void onEvent(SDL_Event *Event);
    void onLoop();
    void onRender();
    void onCleanup();

private:
    bool Running;

    SDL_Window *Screen;
    SDL_Surface *screenSurface; 
};