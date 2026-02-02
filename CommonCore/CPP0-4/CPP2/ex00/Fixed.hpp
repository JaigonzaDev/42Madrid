#pragma once

class Fixed
{
    private:
    int _i;
    static const int _frac;
    
    public: 
    Fixed(void);
    Fixed(const Fixed &copy);
    Fixed &operator= (const Fixed &copy);
    ~Fixed(void);
    int getRawBits ( void ) const;
    void setRawBits ( int const raw );
};