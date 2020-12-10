#include "../../include/Simulator/Simulator.h"

void Simulator::onCleanup()
{
    if (virusSimulation != NULL)
    {
        virusSimulation->end();
        delete virusSimulation;
        virusSimulation = NULL;
    }
    f_handle.logtxt();
    SDL_Quit();
}