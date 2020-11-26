#include "Human.h"

class HumanList
{
public:
    HumanList();
    int getSize();
    void operator+(const Human &human);

private:
    Human *h_list;
    int l_size;
};