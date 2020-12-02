#include "../../include/Simulator/Simulator.h"
#include "../../include/Simulation/Simulation.h"

Simulator::Simulator()
{
    WIDTH = 800;
    HEIGHT = 600;
    Screen = NULL;
    screenSurface = NULL;
    virusSimulation = NULL;
    Running = true;
    simRunning = false;
}

int Simulator::onExecute()
{

    SDL_Event Event; //Create Event Handler

    do
    {
        while (SDL_PollEvent(&Event)) //Handle Events
        {
            onEvent(&Event);
        }

        menu(); //Call the menu

        if (simRunning)
        {
            //Initialize the Simulation
            if (onInit() == false)
            {
                return -1;
            }
            //Create instance of simulation
            virusSimulation = new Simulation(screenSurface->w,
                                             screenSurface->h,
                                             numPeople,
                                             infectionProbability);
        }

        while (simRunning) //Loop Until Exit Call
        {
            while (SDL_PollEvent(&Event)) //Handle Events
            {
                onEvent(&Event);
            }
            onLoop();   //Execute On Each Loop
            onRender(); //Send To Render
        }
        onCleanup(); //Perform Cleanup After Exit Call

    } while (Running);

    return 0;
}

int main(int argc, char *argv[]) //Main Function
{
    Simulator virusSimulator; //Create instance of Simulator

    return virusSimulator.onExecute(); //Run the simulation
}