#include "Priest.h"
#include <iostream>
using namespace std;

Priest::Priest() {
    name = "∆рец";
    health = 28;
    damage = 10;
    lvl = 1;
}

void Priest::GetInfo() {
    Npc::GetInfo();
}
