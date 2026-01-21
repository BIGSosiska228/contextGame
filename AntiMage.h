#pragma once
#include "Npc.h"

class AntiMage : public Npc
{
public:
    std::string abilities[2];

    AntiMage();
    void Create();
};
