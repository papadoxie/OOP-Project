#include "../../include/Simulator/Simulator.h"
#include <iostream>

void Simulator::onEvent(SDL_Event *Event)
{
    if (Event->type == SDL_QUIT) //Exit when X button is clicked
    {
        Running = false;
        std::cout << "EXIT\n";
    }

    if (Event->type == SDL_KEYDOWN) { //Exit when ESCAPE is pressed
        if(SDL_GetKeyboardState(NULL)[SDL_SCANCODE_ESCAPE]){
            Running = false;
            std::cout << "EXIT\n";
        }
    }

    // if (Event->type == SDL_WINDOWEVENT) //Get pixel buffer for resized window
    // {
    //     if (Event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
    //     {
    //         if ((screenSurface = SDL_GetWindowSurface(Screen)) == NULL)
    //         {
    //             std::cout << "ERROR GETTING SURFACE: " << SDL_GetError() << "\n";
    //         }
    //         else
    //         {
    //             WIDTH = screenSurface->w;
    //             HEIGHT = screenSurface->h;
    //             pixbuf = (uint32_t *)screenSurface->pixels;
    //         }
    //     }
    // }
}