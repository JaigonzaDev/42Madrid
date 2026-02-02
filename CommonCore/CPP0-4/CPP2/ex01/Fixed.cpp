#include "Fixed.hpp"
#include <iostream>
#include <math.h>

const int Fixed::_frac = 8;

Fixed::Fixed(void): _i(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed( const int num ) : _i(num * (1 << _frac))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _i(roundf(num * (1 << _frac)))
{
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return(roundf(_i / (1 << _frac)));
}
float Fixed::toFloat(void) const
{
    return((float)_i / (1 << _frac));
}

int Fixed::getRawBits( void ) const
{
    return (this->_i);
}

void Fixed::setRawBits( int const raw )
{
    this->_i = raw;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator= (const Fixed &copy)
{
    std::cout << "Copy Assigment operator called" << std::endl;
    this->_i = copy.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}


Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl; 
}
