#pragma once
#include <iostream>

class Weapon
{
    private:
    std::string _type;

    public:
    const std::string& getType(void);
    void setType(const std::string& string);

    Weapon(std::string weapon): _type(weapon) {}
};