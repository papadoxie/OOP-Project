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

    switch(input){
        case '1':
            simRunning = true;
            break;

        case '5':
            Running = false;
    }

}