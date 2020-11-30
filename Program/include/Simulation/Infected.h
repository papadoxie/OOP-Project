#pragma once

#include "Human.h"
#include "../Simulator/Colors.h"

class Infected : Human
{
public:
    Infected();
    bool isAdjecent();
    void setInfected();

private:
    Colors *colors;
    const uint32_t color;
};