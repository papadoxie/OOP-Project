#pragma once
#include <SDL2/SDL.h>
#include <stdint.h>
#include "../FileHandling/FileHandler.h"
#include "../Simulation/Simulation.h"
#include "Colors.h"

class Simulator
{
public:
    Simulator();     //Sets running status and NULLs pointers
    int onExecute(); //Creates event handler and starts infinite loop

private:
    //Simulation handling
    bool onInit();                  //Initializes the window and surfaces
    void onEvent(SDL_Event *Event); //Handles events
    void onLoop();                  //Stuff to do on each loop
    void onRender();                //Render results of loop
    void onCleanup();               //Cleanup routine

    //Simulation state
    bool Running;    //Is program running
    bool simRunning; //Is a simulation running

    //Simulation arguments
    uint32_t infectionProbability; //Probability of infection spread between humans
    uint32_t numPeople;            //Number of people in the simulation
    Simulation *virusSimulation;   //Instance of a simulation

    //GUI Screen
    SDL_Window *Screen;         //Output window
    SDL_Surface *screenSurface; //Surface to draw on on screen
    uint32_t WIDTH;             //Screen width
    uint32_t HEIGHT;            //Screen height
    uint32_t *pixbuf;           //Pixel buffer
    Colors colors;              //Colors to be used on screen

    //FileHandling
    FileHandler f_handle;

    void menu(); //CLI Menu
};