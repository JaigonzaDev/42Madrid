#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called " << _type << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog Destructor called " << _type << std::endl;
}

Dog::Dog(const Dog& copy)
{
    _type = copy._type;
    _brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog& copy)
{
    if (this != &copy)
    {
        _type = copy._type;
        delete _brain;
        _brain = new Brain(*copy._brain);
    }
    std::cout << "Dog Assigment operator called" << std::endl;
    return (*this);
}

void Dog::makeSound()
{
    std::cout << "WOOF WOOF!!!" << std::endl;
}