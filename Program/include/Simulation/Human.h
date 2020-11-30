#pragma once

#include <stdint.h>
#include "Random.h"
#include "Infected.h"
#include "Clean.h"

class Human
{
public:
    Human(); //Constructor
    uint32_t getx() const;           //Return x position
    uint32_t gety() const;           //Return y position
    void setRandDirection();         //Set a random direction
    void oppDirection();             //Set direction to opposite
    void move();                     //Increment position according to direction

protected:
    uint32_t px, py;               //Position of the Human
    char32_t direction;            //Direction the Human will go in
    Random random;                 //Random generator
    char32_t getDirection() const; //Return direction
};