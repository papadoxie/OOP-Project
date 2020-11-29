#include "../../include/Simulator/Simulator.h"
#include "../../include/Simulation/Simulation.h"

Simulator::Simulator()
{
    WIDTH = 640;
    HEIGHT = 480;
    Screen = NULL;
    screenSurface = NULL;
    virusSimulation = NULL;
    Running = true;
}

int Simulator::onExecute()
{
    if (onInit() == false)
    {
        return -1;
    }

    //Initialize the Simulation
    virusSimulation = new Simulation(screenSurface->w, screenSurface->h);
    SDL_Event Event; //Create Event Handler

    while (Running) //Loop Until Exit Call
    {
        while (SDL_PollEvent(&Event)) //Handle Events
        {
            onEvent(&Event);
        }
        onLoop();   //Execute On Each Loop
        onRender(); //Send To Render
    }

    onCleanup(); //Perform Cleanup After Exit Call

    return 0;
}

int main(int argc, char *argv[]) //Main Function
{
    Simulator virusSimulator; //Create instance of Simulator

    return virusSimulator.onExecute(); //Run the simulation
}