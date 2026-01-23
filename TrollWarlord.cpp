#include "TrollWarlord.h"
#include <iostream>

TrollWarlord::TrollWarlord()
{
    name = "Троль Варлорд";
    health = 35;
    damage = 10;
    armor = 7;
    lvl = 1;
    strength = 30;

    weapons[0] = "топоры (дальний бой)";
    weapons[1] = "топоры (ближний бой)";
    weapons[2] = "ярость войны";
    weapons[3] = "Батл транс";
}

void TrollWarlord::Create()
{
    std::cout << "Введите имя Troll Warlord: ";
    std::cin >> name;

    Npc::Create();
}

void TrollWarlord::GetInfo()
{
    Npc::GetInfo();
    std::cout << "Сила: " << strength << std::endl;
}
