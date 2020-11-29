#pragma once

#include <stdint.h>
#include "City.h"
#include "Time.h"
#include "../Simulator/Colors.h"

class Simulation : City
{
public:
    Simulation(uint32_t width, uint32_t height);
    void draw(uint32_t *pixels);
    void simTime();

private:
    Colors colors;
    Time time;
    void clearScreen(uint32_t *pixels);
    void drawHumans(uint32_t *pixels);
    void drawWalls(uint32_t *pixels);
};