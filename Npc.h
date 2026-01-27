#pragma once
#include <iostream>
#include <string>

class Npc
{
private:
    std::string name;
    int health;
    int maxHealth;
    int damage;
    int armor;
    int lvl;
    int potions;

public:
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

    virtual void GetInfo() const
    {
        std::cout << "Имя: " << name << std::endl;
        std::cout << "Здоровье: " << health << "/" << maxHealth << std::endl;
        std::cout << "Урон: " << damage << std::endl;
        std::cout << "Броня: " << armor << std::endl;
        std::cout << "Уровень: " << lvl << std::endl;
        std::cout << "Зелья: " << potions << std::endl;
    }

    virtual std::string GetClassName() const
    {
        return name;
    }

    virtual ~Npc() {}

    void SetHealth(int hp)
    {
        health = hp;
        maxHealth = hp;
    }

    int GetHealth() const { return health; }
    int GetMaxHealth() const { return maxHealth; }
    int GetDamage() const { return damage; }
    int GetArmor() const { return armor; }
    int GetLevel() const { return lvl; }
    int GetPotions() const { return potions; }
    std::string GetName() const { return name; }


    void TakeDamage(int dmg)
    {
        int effectiveDmg = dmg - armor;
        if (effectiveDmg < 0) effectiveDmg = 0;
        health -= effectiveDmg;
        if (health < 0) health = 0;
    }

    void Heal(int amount)
    {
        health += amount;
        if (health > maxHealth) health = maxHealth;
    }

    bool UsePotion()
    {
        if (potions > 0 && health < maxHealth)
        {
            Heal(20);
            potions--;
            return true;
        }
        return false;
    }

    void AddDamage(int amount) { damage += amount; }
    void AddArmor(int amount) { armor += amount; }
    void AddPotions(int amount) { potions += amount; }
    void SetName(const std::string& n) { name = n; }
};
