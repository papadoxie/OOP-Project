#pragma once

class Clean
{
public:
    void setCareful();

protected:
    static int numClean; //Number of non Infected
    bool isCareful;      //Lower chance of infection
};