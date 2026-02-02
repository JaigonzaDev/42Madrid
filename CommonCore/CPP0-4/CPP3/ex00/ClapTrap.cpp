#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitpoints = 10;
    _energypoints = 10;
    _attackdamage = 0;
    std::cout << "CONSTRUCTOR CALLED" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "DESTRUCTOR CALLED" << std::endl;
}

void ClapTrap::attack (const std::string& target)
{
    if (this->_hitpoints >= 0 && this->_energypoints >= 0)
    {
        this->_energypoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing" << this->_attackdamage << std::endl;
    }
    else
        std::cout << "ClapTrap" << this->_name << "BUG IN THE SYSTEM" << std::endl;
}

void ClapTrap::takeDamage (unsigned int amount)
{
    if (this->_hitpoints >= 0 && this->_energypoints >= 0)
    {
        this->_energypoints--;
        this->_hitpoints -= amount;
        std::cout << "ClapTrap " << this->_name << " LoL! " << " Damage " << amount << std::endl;
    }
    else
        std::cout << "ClapTrap" << this->_name << "BUG IN THE SYSTEM" << std::endl;

}

void ClapTrap::beRepaired (unsigned int amount)
{
    if (this->_hitpoints >= 0 && this->_energypoints >= 0)
    {
        this->_energypoints--;
        this->_hitpoints += amount;
        std::cout << "ClapTrap " << this->_name << " Fixing... " << std::endl;
    }
    else
        std::cout << "ClapTrap" << this->_name << "BUG IN THE SYSTEM" << std::endl;

}