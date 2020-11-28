#include "../../include/Simulator/Simulator.h"

void Simulator::onRender()
{
    SDL_FillRect(screenSurface, NULL, colors.BLACK);
    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(2);

    SDL_FillRect(screenSurface, NULL, colors.PURPLE);
    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(2);

    SDL_FillRect(screenSurface, NULL, colors.GREEN);
    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(2);

    SDL_FillRect(screenSurface, NULL, colors.RED);
    SDL_UpdateWindowSurface(Screen);
    SDL_Delay(2);
}