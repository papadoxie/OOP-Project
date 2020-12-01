#include "../../include/Helpers/Random.h"

Random::Random()
{
    srand(time(0));
}

uint32_t Random::randInt(uint32_t upperBound) const
{
    return (rand() % upperBound) + 1;
}

double_t Random::randDouble(uint32_t upperBound) const
{
    uint32_t lowerBound = 0;
    std::uniform_real_distribution<double_t> unif(lowerBound, upperBound);
    std::default_random_engine re;
    double_t randomDouble = unif(re);
    return randomDouble;
}