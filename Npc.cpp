#include "Npc.h"
#include <iostream>

using namespace std;

void Npc::GetInfo()
{
    cout << "Имя: " << name << endl;
    cout << "Здоровье: " << health << endl;
    cout << "Урон: " << damage << endl;
}

