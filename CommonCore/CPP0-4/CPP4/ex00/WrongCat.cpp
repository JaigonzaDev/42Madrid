#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "Default Destructor called " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
    *this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

void WrongCat::makeSound()
{
    std::cout << "MIAU MIAU!!!" << std::endl;
}