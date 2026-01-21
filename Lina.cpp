#include "Lina.h"
#include <iostream>

Lina::Lina()
{
    name = "Лина";
    health = 25;
    damage = 12;
    lvl = 1;

    spells[0] = "Драгон слейв";
    spells[1] = "Лайт страйк";
    spells[2] = "Лагуна";
}

void Lina::Create()
{
    std::cout << "Введите имя Lina: ";
    std::cin >> name;
}

void Lina::GetInfo()
{
    Npc::GetInfo();
}
