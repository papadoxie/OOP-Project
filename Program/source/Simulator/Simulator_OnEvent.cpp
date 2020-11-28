#include "../../include/Simulator/Simulator.h"

void Simulator::onEvent(SDL_Event *Event)
{
    if (Event->type == SDL_QUIT) //Exit when X button is clicked
    {
        Running = false;
    }

    if (Event->type == SDL_WINDOWEVENT) //Get pixel buffer for resized window
    {
        if (Event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
        {
            screenSurface = SDL_GetWindowSurface(Screen);
            pixbuf = (uint32_t *)screenSurface->pixels;
        }
    }
}