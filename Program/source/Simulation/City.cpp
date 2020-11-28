#include "../../include/Simulation/City.h"

City::City(uint32_t width, uint32_t height)
{
    //Set dimensions of the City
    setDimensions(width, height);

    //Make wall array
    this->walls = new bool *[width];
    for (int i = 0; i < width; i++)
    {
        this->walls[i] = new bool[height];
    }
}

void City::setDimensions(uint32_t width, uint32_t height){
    this->width = width;
    this->height = height;
}

void City::randomBuildings(uint32_t numB){

}