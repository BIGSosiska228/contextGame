#pragma once
#include "Npc.h"
#include <vector>
#include <string>

class Priest : public Npc {
public:
    std::vector<std::string> abilities = { "»сцел€ющий свет", "—в€щенный удар" };

    Priest();
    void GetInfo() override;
};
