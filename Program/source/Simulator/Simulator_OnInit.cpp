#include "../../include/Simulator/Simulator.h"
#include <iostream>

bool Simulator::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error Initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    if (SDL_CreateWindow("Virus Simulator",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 600,
                         SDL_WINDOW_SHOWN) == NULL)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    screenSurface = SDL_GetWindowSurface(Screen);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x1A, 0x1A, 0x1A));

    return true;
}