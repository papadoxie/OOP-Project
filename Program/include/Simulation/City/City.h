#pragma once

#include <stdint.h>
#include <vector>
#include "../Human/Human.h"
#include "../../Helpers/Random.h"

class City
{
public:
    /**
     * Create a new City and fill it with buildings and people.
     * @param width width of city
     * @param height height of city
     * @param infectionProbability probability of a human to get infected
    */
    City(uint32_t width, uint32_t height, uint32_t infectionProbability);
    void setDimensions(uint32_t width, uint32_t height); //Set city dimensions
    void update();                                       //Update the city state
    ~City();                                             //Destructor

protected:
    uint32_t width, height;
    bool **walls;              //Array of buildings
    std::vector<Human> humans; //Vector of humans

    void randomBuildings(uint32_t numB); //Randomly generate buildings on the screen
    void populate(uint32_t numP);        //Add humans to city

private:
    Random random;
    uint32_t hw; //Human Width
    uint32_t hh; //Human Height
    uint32_t infectionProbability;

    void initWalls();                       // Make wall array
    bool isLocOpen(uint32_t x, uint32_t y); //Are given coordinates free
    bool canMove(Human &h);                 //Can the human move
    void move(Human &h);                    //Move human
    //If infected human is nearby then infect current human based on probability
    void infector(Human &h);
};