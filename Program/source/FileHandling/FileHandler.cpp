#include "../../include/FileHandling/FileHandler.h"
#include <iostream>
#include <iomanip>
#include <fstream>

uint32_t FileHandler::getNumberOfLogs()
{
    std::fstream file;
    uint32_t numLogs;

    //Dummy input
    uint32_t dummy;
    double_t dummy2;

    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::in);
    if (!file.is_open())
    {
        std::cout << "LOGFILE NOT FOUND. STARTING A NEW LOG\n";
        return 1;
    }

    while (!file.eof())
    {
        file.read(reinterpret_cast<char *>(&numLogs), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&dummy), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&dummy2), sizeof(double_t));
    }

    file.close();
    return numLogs + 1;
}

void FileHandler::log(uint32_t simID, uint32_t endTime, uint32_t numHumans, double_t infectedPc)
{
    std::fstream file;
    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::out |
                                          std::fstream::app);

    if (!file.is_open())
    {
        std::cout << "LOGFILE NOT FOUND";
    }

    file.write(reinterpret_cast<char *>(&simID), sizeof(uint32_t));
    file.write(reinterpret_cast<char *>(&endTime), sizeof(uint32_t));
    file.write(reinterpret_cast<char *>(&infectedPc), sizeof(double_t));

    file.close();
}

void FileHandler::printAll()
{
    std::fstream file;
    uint32_t simID;
    uint32_t endTime;
    double_t infectedPc;

    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::in);
    if (!file.is_open())
    {
        std::cout << "LOGFILE NOT FOUND\n";
        return;
    }

    std::cout << "---------------------------------\n"
              << "| "
              << " # "
              << " | "
              << " Time "
              << " | "
              << "  % Infected  "
              << " | "
              << "\n"
              << "---------------------------------\n";

    while (true)
    {
        file.read(reinterpret_cast<char *>(&simID), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&endTime), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&infectedPc), sizeof(double_t));

        if (file.eof())
        {
            break;
        }

        std::cout << "| "
                  << std::setw(3) << std::setfill('0') << std::right << simID
                  << " | "
                  << std::setw(6) << std::setfill('0') << std::right << endTime
                  << " | "
                  << std::setw(14) << std::setfill('0') << std::left << infectedPc
                  << " | "
                  << "\n";
    }

    std::cout << "---------------------------------\n";
}