#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void increment(T &value)
{
	++value;
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	const int values[] = {10, 20, 30};
	std::string words[] = {"uno", "dos", "tres"};

	std::cout << "numbers:" << std::endl;
	iter(numbers, 5, print<int>);

	iter(numbers, 5, increment<int>);
	std::cout << "numbers after increment:" << std::endl;
	iter(numbers, 5, print<int>);

	std::cout << "const values:" << std::endl;
	iter(values, 3, print<int>);

	std::cout << "words:" << std::endl;
	iter(words, 3, print<std::string>);
	return 0;
}
