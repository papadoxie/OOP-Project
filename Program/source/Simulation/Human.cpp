#include "../../include/Simulation/Human.h"

Human::Human()
{
    this->setRandDirection(); //Set random direction
}

void Human::setRandDirection()
{
    double_t chance = random.randDouble(1);

    if (chance <= 0.1) //10% chance of changing direction
    {
        uint32_t randint = random.randInt(4); //Randomly select direction

        switch (randint)
        {
        case 0:
            direction = 'U'; //Up
            break;
        case 1:
            direction = 'L'; //Left
            break;
        case 2:
            direction = 'R'; //Right
            break;
        case 3:
            direction = 'D'; //Down
            break;
        }
    }
}

void Human::oppDirection()
{
    switch (direction)
    {
    case 'U': //If Up
        direction = 'D';
        break;
    case 'D': //If Down
        direction = 'U';
        break;
    case 'L': //If Left
        direction = 'R';
        break;
    case 'R': //If Right
        direction = 'L';
        break;
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

uint32_t Human::getx() const
{
    return px;
}

uint32_t Human::gety() const
{
    return py;
}

char32_t Human::getDirection() const {
    return direction;
}