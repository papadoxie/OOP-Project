#include "../../include/Simulation/Simulation.h"
#include <iostream>

Simulation::Simulation(uint32_t width, uint32_t height) : City(width, height)
{
    std::cout << "TIME: " << (uint32_t)time.getCurTime() << "s\n";
    randomBuildings(25);
}

void Simulation::draw(uint32_t *pixels)
{
    //clearScreen(pixels);
    drawWalls(pixels);
    drawHumans(pixels);
}

void Simulation::clearScreen(uint32_t *pixels)
{
    for (uint32_t i = 0; i < width; i++)
    {
        for (uint32_t j = 0; j < height; j++)
        {
            pixels[i + (j * width)] = colors.BLACK;
        }
    }
}

void Simulation::drawWalls(uint32_t *pixels)
{
    for (uint32_t i = 0; i < width; i++)
    {
        for (uint32_t j = 0; j < height; j++)
        {
            if (walls[i][j])
            {
                pixels[i + (j * width)] = colors.GREY;
            }
        }
    }
}

void Simulation::simTime(){
    uint32_t prevtime = time.getPrevTime();
    uint32_t curtime = time.getCurTime();
    if(((curtime % 10) == 0) && (curtime != prevtime)){
        std::cout << "TIME: " << curtime << "s\n";
    }
}

void Simulation::drawHumans(uint32_t *pixels) {}