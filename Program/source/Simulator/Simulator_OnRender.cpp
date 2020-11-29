#include "../../include/Simulator/Simulator.h"

void Simulator::onRender()
{
    SDL_FillRect(screenSurface, NULL, colors.BLACK);
    virusSimulation->draw(pixbuf);
    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(2);
}
