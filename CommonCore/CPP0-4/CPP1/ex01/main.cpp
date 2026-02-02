#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies;
    zombies = zombieHorde(6, "Jaime");
    for (int i = 0; i < 6; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}