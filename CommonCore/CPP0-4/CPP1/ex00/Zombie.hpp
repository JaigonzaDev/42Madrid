#pragma once
#include <iostream>

class Zombie
{
    private:
    std::string _name;

    public:
    void announce(void);

    Zombie(std::string name) : _name(name) {}
    ~Zombie(void)
    {
        std::cout << _name << ": has been destroyed!" << std::endl;
    }
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );