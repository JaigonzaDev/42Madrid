#include "ClapTrap.hpp"

// Hacer mejores pruebas

int main (void)
{
    ClapTrap ob1("Jaime");
    ClapTrap ob2("Corrector");

    ob1.attack("Corrector");
    ob2.takeDamage(1);
    ob2.beRepaired(2);
    return (0);
}