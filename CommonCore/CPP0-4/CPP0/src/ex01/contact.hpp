#ifndef CONTACT_HPP
#define CONTACT_HPP
#endif
#include <iostream>

class Contact
{
    public:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
    
    Contact(): first_name(""), last_name(""), nick_name(""), phone_number(""), darkest_secret("") {}
};