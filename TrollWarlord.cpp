#include "TrollWarlord.h"
#include <iostream>

TrollWarlord::TrollWarlord()
{
    SetName("Троль Варлорд");
    AddDamage(10);
    AddArmor(2);
    

    strength = 30;

    weapons[0] = "топоры (дальний бой)";
    weapons[1] = "топоры (ближний бой)";
    weapons[2] = "ярость войны";
    weapons[3] = "Батл транс";
}


void TrollWarlord::Create()
{
    std::cout << "Введите имя Troll Warlord: ";
    std::string inputName;
    std::cin >> inputName;
    SetName(inputName); 
    SetHealth(32);
    Npc::Create();      
}


void TrollWarlord::GetInfo() const
{
    Npc::GetInfo();   
    std::cout << "Сила: " << strength << std::endl;
}
