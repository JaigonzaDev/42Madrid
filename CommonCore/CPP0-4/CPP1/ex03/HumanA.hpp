#pragma once
#include "Weapon.hpp"

class HumanA
{
    private:
    std::string _name;
    Weapon &_weapon;

    public:
    void attack(void);
    HumanA(std::string name, Weapon &weapontype): _name(name), _weapon(weapontype) {}
};