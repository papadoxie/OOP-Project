#include "../../include/Simulator/Simulator.h"

void Simulator::onRender()
{   
    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(10);
}
