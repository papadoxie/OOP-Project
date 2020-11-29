#include "../../include/Simulation/Random.h"

Random::Random()
{
    srand(time(0));
}

uint32_t Random::randInt(uint32_t upperBound)
{
    return (rand() % upperBound);
}

double_t randDouble(uint32_t upperBound)
{
    uint32_t lowerBound = 0;
    std::uniform_real_distribution<double_t> unif(lowerBound, upperBound);
    std::default_random_engine re;
    double_t randomDouble = unif(re);
    return randomDouble;
}