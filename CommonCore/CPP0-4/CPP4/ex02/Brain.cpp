#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor Called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor Called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = copy._ideas[i];
    }
    return (*this);
}