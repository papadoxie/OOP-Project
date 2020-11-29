#include "../../include/Simulation/City.h"
#include <iostream> //!Remove this later

City::City(uint32_t width, uint32_t height)
{
    //Set dimensions of the City
    setDimensions(width, height);
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

City::~City()
{
    for (uint32_t i = 0; i < width; i++)
    {
        delete[] walls[i];
    }
    delete[] walls;
    delete h_list;
}