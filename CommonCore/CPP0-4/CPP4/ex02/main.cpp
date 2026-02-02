#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Dog* j = new Dog();
    Cat* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    delete i;
    delete j;

    return 0;
}