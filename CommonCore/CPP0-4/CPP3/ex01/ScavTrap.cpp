#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " has been created!" << std::endl;
    _hitpoints = 100;
    _energypoints = 50;
    _attackdamage = 20;
};

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
};

void ScavTrap::attack (const std::string& target)
{
    if (_hitpoints > 0 && _energypoints > 0)
    {
        _energypoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackdamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " can't attack due to insufficient hit points or energy points!" << std::endl;
    }    
};

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}