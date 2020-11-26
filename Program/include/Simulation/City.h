#include "HumanList.h"

class City
{
public:
    City();
    void populate();
    void randomBuildings();
    void update();
    void draw();

private:
    bool **walls;
    int height, width;
};