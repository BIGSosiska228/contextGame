#pragma once
#include "Npc.h"
#include <memory>
#include <iostream>

class Player {
public:
    std::unique_ptr<Npc> character;

    void Create(std::unique_ptr<Npc> npc) { 
        character = std::move(npc);
        if (character) character->GetInfo();
    }

    Npc* GetCurrentCharacter() { return character.get(); }
};
