#include "../../include/Simulator/Simulator.h"

Simulator::Simulator() : WIDTH(640), HEIGHT(480)
{   
    Screen = NULL;
    screenSurface = NULL;
    Running = true;
}

int Simulator::onExecute()
{
    if (onInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while (Running)
    {
        while (SDL_PollEvent(&Event))
        {
            onEvent(&Event);
        }
        onLoop();
        onRender();
    }

    onCleanup();

    return 0;
}

int main(int argc, char *argv[]) //Main Function
{
    Simulator virusSimulator;

    return virusSimulator.onExecute();
}