#include "../../include/Simulator/Simulator.h"

void Simulator::onRender()
{
    SDL_FillRect(screenSurface, NULL, colors.BLACK);
    for(int i = 0; i<screenSurface->w - 1 ; i++){
        for(int j = 0 ; j<screenSurface->h - 1; j++){
            pixbuf[i + j * screenSurface->w] = colors.RED;
        }
        SDL_UpdateWindowSurface(Screen);
        //SDL_Delay(2);
    }    
    
}