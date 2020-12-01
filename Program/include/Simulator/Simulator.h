#pragma once
#include <SDL2/SDL.h>
#include <stdint.h>
#include "../FileHandling/FileHandler.h"
#include "../../include/Simulation/Simulation.h"
#include "../../include/Simulator/Colors.h"

class Simulator
{
public:
    Simulator();     //Sets running status and NULLs pointers
    int onExecute(); //Creates event handler and starts infinite loop

    bool onInit();                  //Initializes the window and surfaces
    void onEvent(SDL_Event *Event); //Handles events
    void onLoop();                  //Stuff to do on each loop
    void onRender();                //Render results of loop
    void onCleanup();               //Cleanup routine

private:
    bool Running;    //Is program running
    bool simRunning; //Is a simulation running

    Simulation *virusSimulation; //Instance of a simulation
    SDL_Window *Screen;          //Output window
    SDL_Surface *screenSurface;  //Surface to draw on on screen

    void menu(); //Menu

    uint32_t WIDTH;  //Screen width
    uint32_t HEIGHT; //Screen height

    uint32_t *pixbuf; //Pixel buffer
    Colors colors;
};