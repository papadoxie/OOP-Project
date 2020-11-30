#pragma once

#include "Human.h"
#include "../Simulator/Colors.h"

class Clean : Human
{
public:
    Clean();
    void setCareful();
    bool getAdjacent();

private:
    bool isCareful;      //Lower chance of infection
    Colors *colors;
    const uint32_t color;
};