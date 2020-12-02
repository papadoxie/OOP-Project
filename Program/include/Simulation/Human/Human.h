#pragma once

#include <stdint.h>
#include "../../Helpers/Random.h"

class Human
{
public:
    Human(uint32_t px, uint32_t py, uint32_t infectionProbability,Random *random); //Constructor
    uint32_t getx() const;                           //Return x position
    uint32_t gety() const;                           //Return y position
    void setRandDirection();                         //Set a random direction
    char32_t getDirection() const;                   //Return direction
    void move();                                     //Increment position according to direction
    bool isInfected() const;                         //Is human infected
    void infect();                                   //Infects the human
    void patientZero();                              //Creates first infected
    double_t getInfectedPc() const;                  //Gets percentage of infected humans
    uint32_t getNumHumans() const;                   //Get number of humans
    void kill();                                     //Remove human

private:
    uint32_t px, py;             //Position of the Human
    char32_t direction;          //Direction the Human will go in
    uint32_t infectionProbability;
    Random *random;              //Random generator
    bool infected;               //Is human infected
    static uint32_t numHumans;   //Total number of humans
    static uint32_t numInfected; //Total number of infected
};