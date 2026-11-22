#include "Data.hpp"
#include "Serializer.hpp"

#include <iostream>

int main()
{
    Data data;
    Data* original;
    uintptr_t raw;
    Data* restored;

    data.number = 42;
    original = &data;
    raw = Serializer::serialize(original);
    restored = Serializer::deserialize(raw);

    std::cout << "original:  " << original << std::endl;
    std::cout << "serialized: " << raw << std::endl;
    std::cout << "restored:  " << restored << std::endl;
    if (original == restored)
        std::cout << "same address" << std::endl;
    else
        std::cout << "different address" << std::endl;
    return 0;
}