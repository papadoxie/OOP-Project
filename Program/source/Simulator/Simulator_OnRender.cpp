#include "../../include/Simulator/Simulator.h"

void Simulator::onRender()
{
    SDL_FillRect(screenSurface, NULL, colors.BLACK);

    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(2);
    
}