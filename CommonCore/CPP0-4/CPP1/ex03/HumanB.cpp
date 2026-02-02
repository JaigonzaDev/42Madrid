#include "HumanB.hpp"

void HumanB::attack(void)
{
    if (_weapon)
        std::cout << _name << " attacks with their" << _weapon->getType() << std::endl;
    else
        std::cout << _name << " attacks with hands" << std::endl;
}
