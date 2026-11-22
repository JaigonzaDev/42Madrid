#include <iostream>
#include <string>
#include "Array.hpp"

static void printResult(const char *name, bool passed)
{
	std::cout << name << ": " << (passed ? "OK" : "FAIL") << std::endl;
}

int main(void)
{
	Array<int> empty;
	printResult("empty array", empty.size() == 0);

	Array<int> numbers(3);
	printResult("size", numbers.size() == 3);
	printResult("default initialization", numbers[0] == 0 && numbers[1] == 0
		&& numbers[2] == 0);

	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;

	Array<int> copy(numbers);
	copy[0] = 99;
	printResult("copy constructor is independent", numbers[0] == 10
		&& copy[0] == 99);

	Array<int> assigned;
	assigned = numbers;
	assigned[1] = 88;
	printResult("assignment is independent", numbers[1] == 20
		&& assigned[1] == 88);

	const Array<int> constant(numbers);
	printResult("const access", constant[2] == 30);

	Array<std::string> words(2);
	words[0] = "hello";
	words[1] = "world";
	printResult("string array", words[0] == "hello" && words[1] == "world");

	bool threw = false;
	try
	{
		numbers[3] = 40;
	}
	catch (const std::exception &exception)
	{
		threw = true;
		std::cout << exception.what() << std::endl;
	}
	printResult("out of bounds", threw);

	return 0;
}
