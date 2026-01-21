#include "TrollWarlord.h"
#include <iostream>

TrollWarlord::TrollWarlord()
{
    name = "“роль ¬арлорд";
    health = 35;
    damage = 10;
    lvl = 1;
    strength = 30;

    weapons[0] = "топоры(дальний бой)";
    weapons[1] = "топоры(ближний бой)";
    weapons[2] = "€рость войны";
    weapons[3] = "Ѕатл транс";
}

void TrollWarlord::Create()
{
    std::cout << "¬ведите им€ Troll Warlord: ";
    std::cin >> name;
}

void TrollWarlord::GetInfo()
{
    Npc::GetInfo();
    std::cout << "—ила: " << strength << std::endl;
}
