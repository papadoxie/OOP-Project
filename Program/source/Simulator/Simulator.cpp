#include "../include/Simulator/Simulator.h"

Simulator::Simulator()
{
}

int Simulator::onExecute()
{
    return 0;
}

int main(int argc, char *argv[])
{
    Simulator virusSimulator;

    return virusSimulator.onExecute();
}