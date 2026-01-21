#pragma once
#include "Npc.h"
#include <vector>
#include <string>

class Archer : public Npc {
public:
    std::vector<std::string> abilities = { "Стрела", "Молниеносный выстрел" };

    Archer();
    void GetInfo() override;
};
