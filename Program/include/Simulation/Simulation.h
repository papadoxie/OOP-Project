#pragma once

#include <stdint.h>
#include <fstream>
#include "./City/City.h"
#include "../Helpers/Time.h"
#include "../Simulator/Colors.h"

class Simulation : private City
{
public:
    Simulation(uint32_t width, uint32_t height);
    void draw(uint32_t *pixels);
    void update(uint32_t *pixels);
    void simTime();
    void end(); //End the simulation
    ~Simulation(); //Destructor


private:
    Colors colors;
    Time time;
    void drawHumans(uint32_t *pixels);
    void drawWalls(uint32_t *pixels);
};