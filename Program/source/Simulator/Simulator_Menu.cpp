#include "../../include/Simulator/Simulator.h"
#include "../../include/Simulation/Simulation.h"
#include <iostream>

void Simulator::menu()
{
    char input;

    std::cout << "\nMENU\n"
              << "1. START SIMULATION\n"
              << "2. PRINT LOG FILE\n"
              << "3. GET AVERAGE OF PREVIOUS SIMULATIONS\n"
              << "4. GET A SIMULATION RECORD BY INDEX\n"
              << "5. REMOVE A SIMULATION RECORD BY INDEX\n"
              << "Q. EXIT\n\n"
              << ">> ";

    std::cin >> input;

    switch (input)
    {
    case '1': //Start a simulation
        do    //Infection probability should be between 1% to 100%
        {
            std::cout << "\nENTER INFECTION PROBABILITY (1-100)\n>> ";
            std::cin >> infectionProbability;
        } while (infectionProbability < 1 || infectionProbability > 100);

        do //Population size greater than 5000 lags too much
        {
            std::cout << "\nENTER POPULATION SIZE (1-10000)\n>> ";
            std::cin >> numPeople;
        } while (numPeople < 1 || numPeople > 5000);

        simRunning = true;
        break;

    case '2':
        f_handle.printAll();
        break;

    case '3':
        break;

    case '4':
        break;

    case '5':
        break;

    case 'Q': //Exit the program
        Running = false;
        break;

    default:
        std::cout << "INVALID SELECTION\n";
        break;
    }
}