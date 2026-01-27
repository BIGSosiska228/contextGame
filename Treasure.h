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
private:
    std::string name;
    ValueQuality quality;

public:
    Treasure(ValueQuality q);


    void ShowInfo() const;


    std::string GetName() const { return name; }
    ValueQuality GetQuality() const { return quality; }


    void SetName(const std::string& n) { name = n; }
    void SetQuality(ValueQuality q) { quality = q; }
};
