#pragma once

#include <random>
#include <stdint.h>

class Random
{
public:
    Random();
    uint32_t randInt(uint32_t upperBound) const;
    double_t randDouble(uint32_t upperBound) const;

private:
};