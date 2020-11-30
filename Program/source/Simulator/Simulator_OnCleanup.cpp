#include "../../include/Simulator/Simulator.h"

void Simulator::onCleanup()
{
    if (virusSimulation != NULL)
    {
        virusSimulation->end();
        virusSimulation->~Simulation();
        virusSimulation = NULL;
    }
    SDL_Quit();
}