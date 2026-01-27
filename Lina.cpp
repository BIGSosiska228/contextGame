#include "Lina.h"
#include <iostream>

Lina::Lina()
{
    SetName("Лина");
    AddDamage(12);
    AddArmor(3);
    

    intelligence = 21;

    spells[0] = "Драгон слейв";
    spells[1] = "Лайт страйк";
    spells[2] = "Лагуна";
}


void Lina::Create()
{
    std::cout << "Введите имя Lina: ";
    std::string inputName;
    std::cin >> inputName;
    SetName(inputName); 
    SetHealth(25);
    Npc::Create();       
}


void Lina::GetInfo() const
{
    Npc::GetInfo();  
    std::cout << "Интеллект: " << intelligence << std::endl;
}
