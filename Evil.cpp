#include "Evil.h"

Evil::Evil(std::string n, int h,int j, int d)
{
    name = n;
    health = h;
    maxHealth = h;
    armor = j;
    damage = d;
    lvl = 1;
}
