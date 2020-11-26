#include "../../include/Simulator/Simulator.h"

Simulator::Simulator()
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

int main(int argc, char *argv[])
{
    Simulator virusSimulator;

    return virusSimulator.onExecute();
}