#pragma once
#include "Npc.h"

class AntiMage : public Npc
{
public:
    std::string abilities[2];
    int agility;

    AntiMage();
    void Create();
    void GetInfo();
};
