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

    int GetIntelligence() const;   
    std::string GetSpell(int index) const; 
    
    void SetIntelligence(int intel); 
    void SetSpell(int index, const std::string& spell); 
};

