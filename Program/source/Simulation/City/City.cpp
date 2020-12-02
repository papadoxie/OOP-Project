#include "../../../include/Simulation/City/City.h"
#include <iterator>

City::City(uint32_t width, uint32_t height, uint32_t infectionProbabiliy)
{   
    this->infectionProbability = infectionProbability;
    humans.clear();
    setDimensions(width, height); //Set dimensions of the City
    initWalls();
}

void City::setDimensions(uint32_t width, uint32_t height)
{
    this->width = width;
    this->height = height;
}

void City::initWalls()
{
    walls = new bool *[width];
    for (uint32_t i = 0; i < width; i++)
    {
        walls[i] = new bool[height];
    }

    for (uint32_t i = 0; i < width; i++)
    {
        for (uint32_t j = 0; j < height; j++)
        {
            walls[i][j] = false;
        }
    }
}

void City::randomBuildings(uint32_t numB)
{
    uint32_t maxSize = width / 5;
    uint32_t minSize = width / 50;

    for (uint32_t i = 0; i < numB; i++)
    {
        uint32_t bx, by, bw, bh;

        bx = random.randInt(width);
        by = random.randInt(height);
        bw = random.randInt(maxSize) + minSize;
        bh = random.randInt(maxSize) + minSize;

        for (uint32_t j = bx; j < (bx + bw); j++)
        {
            if (j < width)
            {
                for (uint32_t k = by; k < (by + bh); k++)
                {
                    if (k < height)
                    {
                        walls[j][k] = true;
                    }
                }
            }
        }
    }
}

void City::populate(uint32_t numP)
{
    uint32_t i = 0;
    while (i < numP)
    {
        uint32_t hx, hy; //x and y coordinates of humans
        hx = random.randInt(width);
        hy = random.randInt(height);

        if ((isLocOpen(hx, hy)))
        {
            humans.push_back(Human(hx, hy, infectionProbability, &random));
            i++;
        }
    }

    humans.at(random.randInt(numP - 1)).patientZero(); //Infect a random human
}

bool City::isLocOpen(uint32_t x, uint32_t y)
{
    if ((x >= width) || (y >= height))
    {
        return false;
    }
    if (walls[x][y])
    {
        return false;
    }
    return true;
}

void City::update()
{
    for (Human &h : humans)
    {
        infector(h);
        move(h);
    }
}

void City::infector(Human &h)
{
    uint32_t fx = h.getx();
    uint32_t fy = h.gety();
    //Range to search for infected
    uint32_t fx_max = fx + 5;
    uint32_t fy_max = fy + 5;
    uint32_t fx_min = fx - 5;
    uint32_t fy_min = fy - 5;

    for (Human &i : humans)
    {
        if (i.getx() >= fx_min && i.getx() <= fx_max)
        {
            if(i.gety() >= fy_min && i.gety() <= fy_max){
                if(i.isInfected()){
                    h.infect();
                }
            }
        }
    }
}

void City::move(Human &h)
{
    if (canMove(h)) //Move if free location available
    {
        h.move();
    }
    else //Otherwise change direction
    {
        h.setRandDirection();
    }
}

bool City::canMove(Human &h)
{
    uint32_t fx = h.getx();
    uint32_t fy = h.gety();
    char32_t d = h.getDirection();

    switch (d)
    {
    case 'U':
        if (isLocOpen(fx, fy + 1))
        {
            return true;
        }
        break;
    case 'D':
        if (isLocOpen(fx, fy - 1))
        {
            return true;
        }
        break;
    case 'L':
        if (isLocOpen(fx - 1, fy))
        {
            return true;
        }
        break;
    case 'R':
        if (isLocOpen(fx + 1, fy))
        {
            return true;
        }
        break;
    }
    return false;
}

City::~City()
{
    for (uint32_t i = 0; i < width; i++)
    {
        delete[] walls[i];
    }
    delete[] walls;

    for(Human &h : humans){
        h.kill();
    }
    humans.clear();
}