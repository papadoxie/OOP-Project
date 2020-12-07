#pragma once

#include "../Simulation/Simulation.h"

class FileHandler
{
public:
    uint32_t getNumberOfLogs();
    void log(uint32_t simID, uint32_t endTime, uint32_t numHumans, double_t infectedPc);
    void printAll();
    void printAverage();
    void printRecord();
    void deleteRecord();

private:
    bool catchException(std::fstream *file);
};