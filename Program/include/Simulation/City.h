#pragma once

#include <stdint.h>
#include <vector>
#include "Clean.h"
#include "Infected.h"
#include "Random.h"

class City
{
public:
    /**
        Create a new City and fill it with buildings and people.
        @param width width of city
        @param height height of city
    */
    City(uint32_t width, uint32_t height);

    void setDimensions(uint32_t width, uint32_t height);
    void update();
    ~City(); //Destructor

private:  
    Random random;
    void initWalls();// Make wall array
    void initHumans(); //Make Human arrays
    void populate(uint32_t numP); //Add humans to city
    bool isLocOpen(uint32_t x, uint32_t y); //Are given coordinates free

protected:
    uint32_t width, height;
    bool **walls; //Array of buildings
    Clean **c_list;
    Infected **i_list;
    void randomBuildings(uint32_t numB); //Randomly generate buildings on the screen

    
};