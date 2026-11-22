#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

static void testVector()
{
	std::vector<int> numbers;
	std::vector<int>::iterator result;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(20);
	numbers.push_back(30);
	result = easyfind(numbers, 20);
	std::cout << "vector: " << *result << std::endl;
}

static void testList()
{
	std::list<int> numbers;
	std::list<int>::iterator result;

	numbers.push_back(4);
	numbers.push_back(8);
	numbers.push_back(15);
	result = easyfind(numbers, 15);
	std::cout << "list: " << *result << std::endl;
}

static void testDeque()
{
	std::deque<int> numbers;
	std::deque<int>::iterator result;

	numbers.push_front(5);
	numbers.push_back(10);
	result = easyfind(numbers, 5);
	std::cout << "deque: " << *result << std::endl;
}

static void testMissingValue()
{
	std::vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	try
	{
		easyfind(numbers, 3);
	}
	catch (const std::exception& error)
	{
		std::cout << "missing value: " << error.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	testDeque();
	testMissingValue();
	return 0;
}