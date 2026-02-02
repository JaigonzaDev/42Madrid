#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " has been created!" << std::endl;
    _hitpoints = 100;
    _energypoints = 100;
    _attackdamage = 30;
};

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
};


void FragTrap::highFivesGuys( void )
{
    std::cout << "FragTrap " << _name << " Can we high five? :3" << std::endl;
}