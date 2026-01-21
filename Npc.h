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
    }

    virtual void GetInfo()
    {
        std::cout << "Èìÿ: " << name << std::endl;
        std::cout << "Çäîðîâüå: " << health << std::endl;
        std::cout << "Óðîí: " << damage << std::endl;
        std::cout << "Óðîâåíü: " << lvl << std::endl;
    }

    virtual std::string GetClassName()
    {
        return name;
    }

    virtual ~Npc() {}
};

