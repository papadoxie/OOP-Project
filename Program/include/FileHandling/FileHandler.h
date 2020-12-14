#pragma once

#include "../Simulation/Simulation.h"

class FileHandler
{
public:
    uint32_t getNumberOfLogs();

    /** Log current simulation results to file
     * @param simID Simulation ID
     * @param endTime Ending Time of Simulation
     * @param numHumans Total Number of Humans
     * @param infectedPc Total Humans infected before exit
     */
    void log(uint32_t simID, uint32_t endTime, uint32_t numHumans, double_t infectedPc);
    void printAll();     //Print all records from file
    void printAverage(); //Print average of all the records in file
    void printRecord();  //Get one record from file by Simulation ID
    void deleteRecord(); //Delete a record from the file by Simulation ID
    void logtxt();       //Log all results in a text file

private:
    bool catchException(std::fstream *file); //Check for any errors in opening the file

    /** Write data to binary file
     * @param file Pointer to file to write to
     * @param simID Simulation ID
     * @param endTime Ending Time of Simulation
     * @param infectedPc Total Humans infected before exit
     */
    void write(std::fstream *file, uint32_t simID, uint32_t endTime, double_t infectedPc);

        /** Read data from binary file
     * @param file Pointer to file to write to
     * @param simID Simulation ID
     * @param endTime Ending Time of Simulation
     * @param infectedPc Total Humans infected before exit
     */
    void read(std::fstream *file, uint32_t &simID, uint32_t &endTime, double_t &infectedPc);
};