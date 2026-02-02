#pragma once
#include "Weapon.hpp"

class HumanB
{
    private:
    std::string _name;
    Weapon *_weapon;

    public:
    void attack(void);
    void setWeapon(Weapon &weapon){
        _weapon = &weapon; }
    HumanB(std::string name): _name(name), _weapon(nullptr) {}
};