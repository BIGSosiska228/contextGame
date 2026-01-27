#include "AntiMage.h"
#include <iostream>

AntiMage::AntiMage()
{

    SetName("Анти маг");
    TakeDamage(0);
    AddDamage(8); 
    AddArmor(1);  


    agility = 26;

    abilities[0] = "Мана брейк";
    abilities[1] = "Мана войд";
}


void AntiMage::Create()
{
    std::cout << "Введите имя Anti mage: ";
    std::string inputName;
    std::cin >> inputName;
    SetName(inputName);  
    SetHealth(22);
    Npc::Create();       
}


void AntiMage::GetInfo() const
{
    Npc::GetInfo();  
    std::cout << "Ловкость: " << agility << std::endl;
}
