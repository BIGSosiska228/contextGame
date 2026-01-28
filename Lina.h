#pragma once
#include "Npc.h"
#include <string>

class Lina : public Npc
{
private:
    std::string spells[3];
    int intelligence;

public:
    Lina();  // Объявление конструктора

    void Create() override;          // Объявление
    void GetInfo() const override;   // Объявление

    int GetIntelligence() const;     // Только объявление!
    std::string GetSpell(int index) const;  // Только объявление!
    
    void SetIntelligence(int intel); // Только объявление!
    void SetSpell(int index, const std::string& spell); // Только объявление!
};
