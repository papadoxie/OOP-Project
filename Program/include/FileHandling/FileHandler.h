#pragma once

#include <fstream>
#include "../Simulation/Simulation.h"

class FileHandler
{

public:
    FileHandler(Simulation *sim);
    void write();
    void read();

private:
    Simulation *sim;
    std::fstream file;
};