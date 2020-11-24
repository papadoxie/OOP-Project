#include "Human.h"

class HumanList
{
private:
    Human *h_list;
    int l_size;

public:
    HumanList();
    int getSize();
    void operator+(const Human &human);
};