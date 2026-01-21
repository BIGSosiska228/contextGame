#pragma once
#include <iostream>
#include <string>

class Npc
{
public:
    std::string name;
    int health;
    int damage;
    int lvl;

    Npc()
    {
        name = "Npc";
        health = 10;
        damage = 2;
        lvl = 1;
    }

    virtual void Create()
    {
        // базовый NPC ничего не создаёт
    }

    virtual void GetInfo()
    {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Здоровье: " << health << std::endl;
        std::cout << "Урон: " << damage << std::endl;
        std::cout << "Уровень: " << lvl << std::endl;
    }

    virtual std::string GetClassName()
    {
        return name;
    }

    virtual ~Npc() {}
};
