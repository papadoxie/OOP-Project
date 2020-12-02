#include "../../include/Simulator/Simulator.h"
#include "../../include/Simulation/Simulation.h"
#include <iostream>

void Simulator::menu()
{
    char input;

    std::cout << "\nMENU\n"
              << "1. START SIMULATION\n"
              << "2. GET AVERAGE OF PREVIOUS SIMULATIONS\n"
              << "3. GET A SIMULATION RECORD BY INDEX\n"
              << "4. REMOVE A SIMULATION RECORD BY INDEX\n"
              << "5. EXIT\n\n"
              << ">> ";

    std::cin >> input;

    switch (input)
    {
    case '1': //Start a simulation
        do
        {
            std::cout << "\nENTER INFECTION PROBABILITY (1-100)\n>> ";
            std::cin >> infectionProbability;
        } while (infectionProbability < 1 || infectionProbability > 100);

        std::cout << "\nENTER POPULATION SIZE\n>> ";
        std::cin >> numPeople;

        simRunning = true;
        break;

    case '2':
        break;

    case '3':
        break;

    case '4':
        break;

    case '5': //Exit the program
        Running = false;
        break;

    default:
        std::cout << "INVALID SELECTION\n";
        break;
    }
}