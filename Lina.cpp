#include "Lina.h"
#include <iostream>

Lina::Lina()
{
    name = "Лина";
    health = 26;
    damage = 12;
    armor = 3;
    lvl = 1;
    intelligence = 21;

    spells[0] = "Драгон слейв";
    spells[1] = "Лайт страйк";
    spells[2] = "Лагуна";
}

void Lina::Create()
{
    std::cout << "Введите имя Lina: ";
    std::cin >> name;
    Npc::Create();
}

void Lina::GetInfo()
{
    Npc::GetInfo();
    std::cout << "Интеллект: " << intelligence << std::endl;
}
