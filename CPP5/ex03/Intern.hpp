#pragma once

#include <string>

class AForm;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern(void);

        AForm* makeForm(const std::string& formName,
                        const std::string& target) const;
};