#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called " << _type << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat Destructor called " << _type << std::endl;
}

Cat::Cat(const Cat& copy)
{
    _type = copy._type;
    _brain = new Brain(*copy._brain);
    std::cout << "Cat copy contructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
        delete _brain;
        _brain = new Brain(*copy._brain);
    }
    
    std::cout << "Cat Assigment operator called" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "MIAU MIAU!!!" << std::endl;
}