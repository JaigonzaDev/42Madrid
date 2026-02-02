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

Fixed Fixed::operator+(const Fixed &copy)
{
    return(this->_i + copy._i);
}

Fixed Fixed::operator-(const Fixed &copy)
{
    return(this->_i - copy._i);
}

Fixed Fixed::operator*(const Fixed &copy)
{
    return (this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy)
{
    return (this->toFloat() / copy.toFloat());
}

bool Fixed::operator==(const Fixed &copy)
{
    if (this->getRawBits() == copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &copy)
{
    if (this->getRawBits() <= copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &copy)
{
    if (this->getRawBits() < copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>(const Fixed &copy)
{
    if (this->getRawBits() > copy.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &copy)
{
    if (this->getRawBits() >= copy.getRawBits())
        return (true);
    return (false);
}

Fixed &Fixed::operator++(void)
{
    return (++this->_i, *this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_i++;
    return (temp);
}

Fixed &Fixed::operator--(void)
{
    return (--this->_i, *this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_i--;
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}