#include "../../include/Simulator/Simulator.h"
#include <iostream>

bool Simulator::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Error Initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    if ((Screen = SDL_CreateWindow("Virus Simulator",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         WIDTH, HEIGHT,
                         SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) == NULL)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    if ((screenSurface = SDL_GetWindowSurface(Screen)) == NULL)
    {
        std::cout << "Error Getting Surface: " << SDL_GetError() << std::endl;
        return false;
    }

    pixbuf = (uint32_t*)(screenSurface->pixels);
    std::cout << SDL_GetPixelFormatName(screenSurface->format->format) << std::endl;

    return true;
}