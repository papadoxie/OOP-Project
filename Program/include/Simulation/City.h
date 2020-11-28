#pragma once

#include <stdint.h>
#include "HumanList.h"

class City
{
public:
    /**
        Create a new City and fill it with buildings and people.
        @param width width of city
        @param height height of city
    */
    City(uint32_t width, uint32_t height);

    void populate(uint32_t numP);
    void randomBuildings(uint32_t numB);
    void setDimensions(uint32_t width, uint32_t height);
    void update();
    void draw();

private:
    bool **walls;
    uint32_t width, height;
    HumanList *h_list;
};