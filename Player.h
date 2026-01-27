#pragma once
#include "Npc.h"
#include <memory>
#include <iostream>

class Player {
private:
    std::unique_ptr<Npc> character;  

public:

    void Create(std::unique_ptr<Npc> npc) {
        character = std::move(npc);
        if (character) character->GetInfo();
    }

 
    Npc* GetCurrentCharacter() const { return character.get(); }

  
    bool HasCharacter() const { return character != nullptr; }
};
