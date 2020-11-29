#pragma once
#include <SDL2/SDL.h>
#include <stdint.h>
#include "../../include/Simulation/Simulation.h"
#include "../../include/Simulator/Colors.h"

class Simulator
{
public:
    Simulator();     //Sets running status and NULLs pointers
    int onExecute(); //Creates event handler and starts infinite loop

    bool onInit();                  //Initializes the window and surfaces
    void onEvent(SDL_Event *Event); //Handles events
    void onLoop();
    void onRender();
    void onCleanup();

private:
    bool Running;

    Simulation *virusSimulation;
    SDL_Window *Screen;
    SDL_Surface *screenSurface;

    uint32_t WIDTH;  //Screen width
    uint32_t HEIGHT; //Screen height

    uint32_t *pixbuf; //Pixel buffer
    Colors colors;
};