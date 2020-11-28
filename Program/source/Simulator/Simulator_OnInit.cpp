#include "../../include/Simulator/Simulator.h"
#include <iostream>

bool Simulator::onInit()
{   
    //Resource Log
    std::cout << "Platform: " << SDL_GetPlatform() << "\n";
    std::cout << "System Resources" << "\n";
    std::cout << "RAM: " << SDL_GetSystemRAM() << " MB" << "\n\n";

    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "ERROR INITIALIZING SDL: " << SDL_GetError() << "\n";
        return false;
    }
    std::cout << "SDL INITIALIZED SUCCESFULLY: " << SDL_GetRevisionNumber() << "\n";

    //Create Window
    if ((Screen = SDL_CreateWindow("Virus Simulator",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         WIDTH, HEIGHT,
                         SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)) == NULL)
    {
        std::cout << "ERROR CREATING WINDOW: " << SDL_GetError() << "\n";
        return false;
    }
    std::cout << "WINDOW CREATED. SIZE: " << WIDTH << " x " << HEIGHT << "\n"; 

    //Get SDL Surface from Window
    if ((screenSurface = SDL_GetWindowSurface(Screen)) == NULL)
    {
        std::cout << "ERROR GETTING SURFACE: " << SDL_GetError() << "\n";
        return false;
    }
    std::cout << "SURFACE SET SUCCESFULLY" << "\n";

    //Get the pixel buffer
    pixbuf = (uint32_t*)(screenSurface->pixels);
    std::cout << "PIXEL FORMAT: " << SDL_GetPixelFormatName(screenSurface->format->format) << "\n\n";

    return true;
}