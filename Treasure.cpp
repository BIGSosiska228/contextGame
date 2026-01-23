#include "Treasure.h"
#include <iostream>

Treasure::Treasure(ValueQuality q)
{
    quality = q;
}

void Treasure::ShowInfo()
{
    std::cout << "Сокровище: " << name << std::endl;
}
