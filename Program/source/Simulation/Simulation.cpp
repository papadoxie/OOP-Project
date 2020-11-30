#include "../../include/Simulation/Simulation.h"
#include "../../include/Simulation/FileHandler.h"
#include <iostream>

Simulation::Simulation(uint32_t width, uint32_t height) : City(width, height)
{
    std::cout << "TIME: " << (uint32_t)time.getCurTime() << "s\n";
    randomBuildings(40);
    populate(250);
}

void Simulation::draw(uint32_t *pixels)
{
    drawWalls(pixels);
    drawHumans(pixels);
}

void Simulation::update(uint32_t *pixels){
    simTime();
    City::update();
    draw(pixels);
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

void Simulation::drawHumans(uint32_t *pixels)
{
    uint32_t hw = 3 * width / 640;  //Size according to width
    uint32_t hh = 3 * height / 480; //Size according to height

    for (Human &h : humans)
    {
        uint32_t hx = h.getx();
        uint32_t hy = h.gety();

        if (h.isInfected()) //Draw red for infected
        {
            for (uint32_t i = hx; i < (hx + hw); i++)
            {
                if (i < width)
                {
                    for (uint32_t j = hy; j < (hy + hh); j++)
                    {
                        if (j < height)
                        {
                            pixels[i + (j * width)] = colors.RED;
                        }
                    }
                }
            }
            continue;
        }

        for (uint32_t i = hx; i < (hx + hw); i++) //Draw green for uninfected
        {
            if (i < width)
            {
                for (uint32_t j = hy; j < (hy + hh); j++)
                {
                    if (j < height)
                    {
                        pixels[i + (j * width)] = colors.GREEN;
                    }
                }
            }
        }
    }
}

void Simulation::simTime()
{
    uint32_t prevtime = time.getPrevTime();
    uint32_t curtime = time.getCurTime();
    if (((curtime % 10) == 0) && (curtime != prevtime))
    {
        std::cout << "TIME: " << curtime << "s\t\t\t"
                  << "INFECTED: " << humans.at(0).getInfectedPc() << "%\n";
    }
}

void Simulation::end(){
    std::cout << "SIMULATION RAN FOR: " << time.getCurTime() << "s\n"
              << "TOTAL HUMANS: " << humans.at(0).getNumHumans() << "\n"
              << "INFECTED: " << humans.at(0).getInfectedPc() << "%\n";

    FileHandler handler(this);
}

Simulation::~Simulation(){
}
