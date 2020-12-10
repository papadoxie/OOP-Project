#include "../../include/FileHandling/FileHandler.h"
#include <iostream>
#include <iomanip>
#include <fstream>

uint32_t FileHandler::getNumberOfLogs()
{
    std::fstream file;
    uint32_t numLogs;
    uint32_t simID;

    //Dummy input
    u_long dummy;

    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::in);
    if (catchException(&file))
    {
        std::cout << "CREATING NEW LOG IN ./bin\n";
        return 1;
    }

    while (!file.eof())
    {
        file.read(reinterpret_cast<char *>(&numLogs), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&dummy), (sizeof(uint32_t) + sizeof(double_t)));
        if (numLogs != 1330380800)
        {
            simID = numLogs;
        }
    }

    file.close();
    return simID + 1;
}

void FileHandler::log(uint32_t simID, uint32_t endTime, uint32_t numHumans, double_t infectedPc)
{
    std::fstream file;
    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::out |
                                          std::fstream::app);

    if (catchException(&file))
    {
        return;
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
    if (catchException(&file))
    {
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

        if (simID == 1330380800)
        {
            continue;
        }

        std::cout << "| "
                  << std::setw(3) << std::right << simID
                  << " | "
                  << std::setw(6) << std::right << endTime
                  << " | "
                  << std::setw(14) << std::right << infectedPc
                  << " | "
                  << "\n";
    }

    std::cout << "---------------------------------\n";
    file.close();
}

void FileHandler::printAverage()
{
    std::fstream file;
    uint32_t simID;
    uint32_t endTime;
    double_t infectedPc;
    double_t avgTime = 0;
    u_long avgInfected = 0;

    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::in);
    if (catchException(&file))
    {
        return;
    }

    while (true)
    {
        file.read(reinterpret_cast<char *>(&simID), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&endTime), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&infectedPc), sizeof(double_t));

        if (file.eof())
        {
            break;
        }

        if (simID == 1330380800)
        {
            continue;
        }

        avgTime = avgTime + endTime;
        avgInfected = avgInfected + infectedPc;
    }

    avgTime = (double_t)avgTime / simID;
    avgInfected = (double_t)avgInfected / simID;

    std::cout << "ON AVERAGE "
              << avgInfected << "% POPULATION WAS INFECTED IN "
              << avgTime << " SECONDS\n";

    file.close();
}

void FileHandler::printRecord()
{
    std::fstream file;
    uint32_t simID;
    uint32_t endTime;
    double_t infectedPc;
    uint32_t index;

    std::cout << "ENTER SIMULATION NUMBER\n>> ";
    std::cin >> index;

    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::in);
    if (catchException(&file))
    {
        return;
    }

    while (true)
    {
        file.read(reinterpret_cast<char *>(&simID), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&endTime), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&infectedPc), sizeof(double_t));

        if (file.eof())
        {
            break;
        }

        if (simID == 1330380800)
        {
            continue;
        }

        if (simID == index)
        {
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

            std::cout << "| "
                      << std::setw(3) << std::right << simID
                      << " | "
                      << std::setw(6) << std::right << endTime
                      << " | "
                      << std::setw(14) << std::right << infectedPc
                      << " | "
                      << "\n";

            std::cout << "---------------------------------\n";

            file.close();
            return;
        }
    }

    std::cout << "SIMULATION RECORD NOT FOUND\n";
    file.close();
}

void FileHandler::deleteRecord()
{
    std::fstream file;
    uint32_t simID;
    uint32_t endTime;
    double_t infectedPc;
    uint32_t index;

    std::cout << "ENTER SIMULATION NUMBER\n>> ";
    std::cin >> index;

    file.open("./bin/Simulation.log", std::fstream::binary |
                                          std::fstream::in |
                                          std::fstream::out);
    if (catchException(&file))
    {
        return;
    }

    while (true)
    {
        std::streampos position = file.tellg();

        file.read(reinterpret_cast<char *>(&simID), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&endTime), sizeof(uint32_t));
        file.read(reinterpret_cast<char *>(&infectedPc), sizeof(double_t));

        if (file.eof())
        {
            break;
        }

        if (simID == index)
        {
            file.seekp(position);
            file.write("\0", sizeof(uint32_t));
            file.write("\0", sizeof(uint32_t));
            file.write("\0", sizeof(double_t));
            file.close();
            return;
        }
    }

    std::cout << "SIMULATION RECORD NOT FOUND\n";
    file.close();
}

void FileHandler::logtxt()
{

    std::fstream binFile;
    std::fstream txtFile;
    uint32_t simID;
    uint32_t endTime;
    double_t infectedPc;

    binFile.open("./bin/Simulation.log", std::fstream::binary |
                                             std::fstream::in);

    txtFile.open("./bin/Simulation.txt", std::fstream::out);

    if (catchException(&binFile) || catchException(&txtFile))
    {
        return;
    }

    txtFile << "---------------------------------\n"
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
        binFile.read(reinterpret_cast<char *>(&simID), sizeof(uint32_t));
        binFile.read(reinterpret_cast<char *>(&endTime), sizeof(uint32_t));
        binFile.read(reinterpret_cast<char *>(&infectedPc), sizeof(double_t));

        if (binFile.eof())
        {
            break;
        }

        if (simID == 1330380800)
        {
            continue;
        }

        txtFile << "| "
                  << std::setw(3) << std::right << simID
                  << " | "
                  << std::setw(6) << std::right << endTime
                  << " | "
                  << std::setw(14) << std::right << infectedPc
                  << " | "
                  << "\n";
    }

    txtFile << "---------------------------------\n";

    binFile.close();
    txtFile.close();
}

bool FileHandler::catchException(std::fstream *file)
{
    if (!file->is_open())
    {
        std::cout << "LOGFILE NOT FOUND\n";
        return true;
    }
    return false;
}