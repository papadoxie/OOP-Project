#pragma once

#include <time.h>

class Time
{
public:
    void startTime();
    void stopTime();
    double getCurTime();

private:
    double start;
};