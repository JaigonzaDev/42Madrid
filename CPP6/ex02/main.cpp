#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    Base* generated;
    A objectA;
    B objectB;
    C objectC;

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    generated = generate();
    std::cout << "Generated pointer: ";
    identify(generated);
    std::cout << "Generated reference: ";
    identify(*generated);
    delete generated;

    std::cout << "A pointer: ";
    identify(&objectA);
    std::cout << "A reference: ";
    identify(objectA);
    std::cout << "B pointer: ";
    identify(&objectB);
    std::cout << "B reference: ";
    identify(objectB);
    std::cout << "C pointer: ";
    identify(&objectC);
    std::cout << "C reference: ";
    identify(objectC);
    return 0;
}
