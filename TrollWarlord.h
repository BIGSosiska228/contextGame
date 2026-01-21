#pragma once
#include "Npc.h"

class TrollWarlord : public Npc
{
public:
    int strength;
    std::string weapons[4];

    TrollWarlord();
    void Create();
    void GetInfo();
};
