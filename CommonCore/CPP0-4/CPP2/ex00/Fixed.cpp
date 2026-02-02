#include "Fixed.hpp"
#include <iostream>

const int Fixed::_frac = 8;

Fixed::Fixed(void): _i(0)
{
	std::cout << "Fixed object created with default constructor" << std::endl; 
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_i);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "Fixed object copied" << std::endl;
    this->_i = raw;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed &Fixed::operator= (const Fixed &copy)
{
    std::cout << "Assigment operator called" << std::endl;
    this->_i = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed object destroyed" << std::endl; 
}
