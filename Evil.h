#pragma once
#include "Npc.h"
#include <string>

class Evil : public Npc
{
public:
    Evil(std::string n, int h, int a, int d);
};
