#pragma once
#include "Npc.h"
#include <string>

class TrollWarlord : public Npc
{
private:
    int strength;
    std::string weapons[4];

public:
    TrollWarlord();

    
    void Create() override;
    void GetInfo() const override;

    
    int GetStrength() const { return strength; }
    std::string GetWeapon(int index) const
    {
        if (index < 0 || index > 3) return "";
        return weapons[index];
    }

   
    void SetStrength(int s) { strength = s; }
    void SetWeapon(int index, const std::string& weapon)
    {
        if (index < 0 || index > 3) return;
        weapons[index] = weapon;
    }
};
