#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#endif
#include "contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:
    Contact contacts[8];
    int total_contacts;

    public:
    void ADD(void);
    void SEARCH(void);
    void EXIT(void);

    PhoneBook(): total_contacts(0) {};
};