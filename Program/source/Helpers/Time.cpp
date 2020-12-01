#include "../../include/Simulation/Time.h"

Time::Time()
{
    start = std::chrono::system_clock::now();
}

uint32_t Time::getCurTime()
{   
    prev = std::chrono::system_clock::now();
    std::chrono::duration<double> t = (std::chrono::system_clock::now() - start);
    return (uint32_t)(t.count());
}

uint32_t Time::getPrevTime(){
    std::chrono::duration<double> t = prev - start;
    return (uint32_t)(t.count());
}
