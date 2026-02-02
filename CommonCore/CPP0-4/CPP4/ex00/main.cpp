#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal* meta = new Animal();
    Animal* j = new Dog();
    Animal* i = new Cat();
    WrongAnimal* animal = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    animal->makeSound();
    delete meta;
    delete i;
    delete j;
    delete animal;

    return 0;
}