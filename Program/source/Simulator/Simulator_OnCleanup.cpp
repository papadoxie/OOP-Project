#include "../../include/Simulator/Simulator.h"

void Simulator::onCleanup()
{
    if (virusSimulation != NULL)
    {
        virusSimulation->end();
        delete virusSimulation;
        virusSimulation = NULL;
    }
    SDL_Quit();
}