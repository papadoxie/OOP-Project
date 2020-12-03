#pragma once

#include <stdint.h>
#include <fstream>
#include "./City/City.h"
#include "../Helpers/Time.h"
#include "../Simulator/Colors.h"

class Simulation : private City
{
public:
    /**
     * Create new simulation
     * @param width width of the city in pixels
     * @param height height of the city pixels
     * @param simID Unique ID of the current simulation
     * @param numPeople number of people in the city
     * @param infectionProbability probability of a human to get infected
    */
    Simulation(uint32_t width,
               uint32_t height,
               uint32_t simID,
               uint32_t numPeople,
               uint32_t infectionProbability);

    void draw(uint32_t *pixels);
    void update(uint32_t *pixels);
    void simTime();
    void end();    //End the simulation

private:
    uint32_t ID;
    Colors colors;
    Time time;
    void drawHumans(uint32_t *pixels);
    void drawWalls(uint32_t *pixels);
};