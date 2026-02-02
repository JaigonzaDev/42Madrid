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
    ~Fixed(void);

    Fixed operator+(const Fixed &copy);
    Fixed operator-(const Fixed &copy);
    Fixed operator*(const Fixed &copy);
    Fixed operator/(const Fixed &copy);

    Fixed &operator= (const Fixed &copy);
    bool operator==(const Fixed &copy);
    bool operator!=(const Fixed &copy);
    bool operator<=(const Fixed &copy);
    bool operator>=(const Fixed &copy);
    bool operator<(const Fixed &copy);
    bool operator>(const Fixed &copy);

    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    static Fixed &min ( Fixed &fp1, Fixed &fp2 );
    static const Fixed &min ( const Fixed &fp1, const Fixed &fp2 );
    static Fixed &max ( Fixed &fp1, Fixed &fp2 );
    static const Fixed &max ( const Fixed &fp1, const Fixed &fp2 );

    friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);

    int getRawBits ( void ) const;
    void setRawBits ( int const raw );
    float toFloat(void) const;
    int toInt(void) const;
};