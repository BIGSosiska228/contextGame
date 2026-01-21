#pragma once
#include <string>

enum ValueQuality
{
    мусор,
    обычное,
    редкое,
    мифическое,
    легендарное
};

class Treasure
{
public:
    std::string name;
    ValueQuality quality;

    Treasure(ValueQuality q);
    void ShowInfo();
};
