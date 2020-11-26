#include "../../include/Simulator/Simulator.h"

void Simulator::onCleanup(){
    SDL_DestroyWindow(Screen);
    SDL_Quit();
}