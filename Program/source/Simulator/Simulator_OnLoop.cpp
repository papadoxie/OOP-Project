#include "../../include/Simulator/Simulator.h"
#include <iostream>

void Simulator::onLoop(){
    SDL_FillRect(screenSurface, NULL, colors.BLACK);
    virusSimulation->update(pixbuf);
}