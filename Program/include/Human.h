#include "Infected.h"
#include "Clean.h"

class Human : Infected, Clean //Inherits Infected and Clean
{
private:
    int px, py; //Position of the Human
    char direction; //Direction the Human will go in
    bool infected; //Is human infected or not

public:
    Human(); //Constructor
    char getDirection();
    void setDirection();
    bool getAdjacent();
};