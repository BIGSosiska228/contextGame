#include "AntiMage.h"
#include <iostream>

AntiMage::AntiMage()
{
    name = "Анти маг";
    health = 40;
    damage = 8;
    lvl = 1;

    abilities[0] = "Мана берн";
    abilities[1] = "Мана войд";
}

void AntiMage::Create()
{
    std::cout << "Введите имя Anti mage: ";
    std::cin >> name;
}
