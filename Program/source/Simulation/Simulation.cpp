#include "../../include/Simulation/Simulation.h"
#include <iostream>

Simulation::Simulation(uint32_t width, uint32_t height)
{   
    city = new City(width, height);
}
