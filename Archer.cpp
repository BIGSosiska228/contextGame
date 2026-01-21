#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer() {
    name = "Лучник";
    health = 30;
    damage = 11;
    lvl = 1;
}

void Archer::GetInfo() {
    Npc::GetInfo();
}
