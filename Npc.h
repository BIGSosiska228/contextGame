#pragma once
#include <iostream>
#include <string>

class Npc
{
public:
    std::string name;
    int health;
    int maxHealth;
    int damage;
    int armor;
    int lvl;
    int potions; 

    Npc()
    {
        name = "Npc";
        health = 10;
        maxHealth = health;
        armor = 5;
        damage = 2;
        lvl = 1;
        potions = 2; 
    }

    
    virtual void Create()
    {
        maxHealth = health; 
        potions = 2;
    }


    bool UsePotion()
    {
        if (potions > 0 && health < maxHealth)
        {
            health += 20;
            if (health > maxHealth)
                health = maxHealth;

            potions--;
            return true;
        }
        return false;
    }

    virtual void GetInfo()
    {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Здоровье: " << health << "/" << maxHealth << std::endl;
        std::cout << "Урон: " << damage << std::endl;
        std::cout << "Броня: " << armor << std::endl;
        std::cout << "Уровень: " << lvl << std::endl;
        std::cout << "Зелья: " << potions << std::endl;
    }

    virtual std::string GetClassName()
    {
        return name;
    }

    virtual ~Npc() {}
};
