#pragma once
#include <iostream>

class Zombie
{
    private:
    std::string _name;

    public:
    void announce(void);
    void setname(std::string name)
    {
        _name = name;
    }

    ~Zombie(void)
    {
        std::cout << _name << ": has been destroyed!" << std::endl;
    }
};

Zombie* zombieHorde( int N, std::string name);
