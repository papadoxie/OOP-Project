#include "../../include/Simulation/Human.h"

uint32_t Human::numHumans = 0;
uint32_t Human::numInfected = 0;

Human::Human(uint32_t px, uint32_t py, Random *random)
{
    this->px = px;
    this->py = py;
    this->random = random;
    this->setRandDirection(); //Set random direction
    numHumans++;
    infected = false;
}

void Human::setRandDirection()
{
    uint32_t chance = random->randInt(100);

    if (chance <= 5) //10% chance of changing direction
    {
        uint32_t randint = random->randInt(4); //Randomly select direction

        switch (randint)
        {
        case 1:
            direction = 'U'; //Up
            break;
        case 2:
            direction = 'L'; //Left
            break;
        case 3:
            direction = 'R'; //Right
            break;
        case 4:
            direction = 'D'; //Down
            break;
        }
    }
}

void Human::move()
{
    switch (direction)
    {
    case 'U': //If Up
        py++;
        break;
    case 'D': //If Down
        py--;
        break;
    case 'L': //If Left
        px--;
        break;
    case 'R': //If Right
        px++;
        break;
    }
    setRandDirection();
}

bool Human::isInfected() const
{
    return infected;
}

void Human::infect()
{   
    if(infected){
        return;
    }

    uint32_t chance = random->randInt(100);
    if (chance <= 5) //5% chance to infect
    {
        infected = true;
        numInfected++;
    }
}

void Human::patientZero()
{
    infected = true;
    numInfected++;
}

uint32_t Human::getx() const
{
    return px;
}

uint32_t Human::gety() const
{
    return py;
}

double_t Human::getInfectedPc() const
{
    return ((double_t)numInfected / (double_t)numHumans) * 100;
}

uint32_t Human::getNumHumans() const
{
    return numHumans;
}

char32_t Human::getDirection() const
{
    return direction;
}

void Human::kill(){
    if(infected){
        numInfected--;
    }
    numHumans--;
}