#include "Evil.h"

Evil::Evil(std::string n, int h, int a, int d)
{
    SetName(n);


    TakeDamage(0);   
    Heal(h);    



    AddDamage(d);
    AddArmor(a);
}
