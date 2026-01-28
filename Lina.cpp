#pragma once
#include "Npc.h"
#include <string>

class Lina : public Npc
{
private:
    std::string spells[3];
    int intelligence;

public:
    Lina();

    void Create() override;
    void GetInfo() const override;


    int GetIntelligence() const { return intelligence; }
    std::string GetSpell(int index) const
    {
        if (index < 0 || index > 2) return "";
        return spells[index];
    }


    void SetIntelligence(int intel) { intelligence = intel; }
    void SetSpell(int index, const std::string& spell)
    {
        if (index < 0 || index > 2) return;
        spells[index] = spell;
    }
};
