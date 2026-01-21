#pragma once
#include "Npc.h"

class Lina : public Npc
{
public:
    std::string spells[3];

    Lina();
    void Create();
    void GetInfo();
};
