#pragma once
#include "Npc.h"

class Lina : public Npc
{
public:
    std::string spells[3];
    int intelligence;

    Lina();
    void Create();
    void GetInfo();
};
