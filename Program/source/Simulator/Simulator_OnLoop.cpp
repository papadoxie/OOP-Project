#include "../../include/Simulator/Simulator.h"
#include <iostream>

void Simulator::onLoop(){
    virusSimulation->simTime();
}