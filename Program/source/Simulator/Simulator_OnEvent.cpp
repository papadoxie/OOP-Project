#include "../../include/Simulator/Simulator.h"

void Simulator::onEvent(SDL_Event *Event)
{
    if (Event->type == SDL_QUIT)
    {
        Running = false;
    }
}