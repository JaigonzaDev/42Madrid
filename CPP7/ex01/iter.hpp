#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *array, const std::size_t length, F function)
{
    for (std::size_t i = 0; i < length; ++i)
        function(array[i]);
}

template <typename T>
void print(const T &value)
{
    std::cout << value << std::endl;
}

#endif