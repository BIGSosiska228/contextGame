#include "AntiMage.h"
#include <iostream>

AntiMage::AntiMage()
{
    name = "Анти маг";
    health = 25;
    damage = 8;
    armor = 1;
    lvl = 1;
    agility = 26;

    abilities[0] = "Мана брейк";
    abilities[1] = "Мана войд";
}

void AntiMage::Create()
{
    std::cout << "Введите имя Anti mage: ";
    std::cin >> name;
    Npc::Create();
}
void AntiMage::GetInfo()
{
    Npc::GetInfo();
    std::cout << "Ловкость: " << agility << std::endl;
}

