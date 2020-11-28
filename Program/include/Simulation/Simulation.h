#pragma once

#include <stdint.h>
#include "City.h"

class Simulation
{
public:
    Simulation(uint32_t width, uint32_t height);

private:
    City *city;
};