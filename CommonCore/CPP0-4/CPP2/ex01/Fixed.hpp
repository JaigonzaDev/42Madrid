#pragma once
#include <iostream>

class Fixed
{
    private:
    int _i;
    static const int _frac;
    
    public: 
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &copy);
    Fixed(void);

    Fixed &operator= (const Fixed &copy);
    friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);
    ~Fixed(void);

    int getRawBits ( void ) const;
    void setRawBits ( int const raw );
    float toFloat(void) const;
    int toInt(void) const;
};