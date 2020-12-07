#include "../../include/Simulator/Simulator.h"
#include <iostream>

void Simulator::onLoop()
{
    SDL_FillRect(screenSurface, NULL, colors.BLACK);
    if (virusSimulation->update(pixbuf))
    {
        simRunning = false;
        std::cout << "\nSTOPPED SIMULATION\n";
    }
}