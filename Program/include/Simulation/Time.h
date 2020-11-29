#pragma once

#include <chrono>
#include <stdint.h>

class Time
{
public:
    Time();
    void stopTime();
    uint32_t getCurTime();
    uint32_t getPrevTime();

private:
    std::chrono::_V2::system_clock::time_point start;
    std::chrono::_V2::system_clock::time_point prev;
};