#include <iostream>
#include <vector>
#include "Span.hpp"

static void testExample()
{
	Span span(5);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);
	std::cout << "example shortest: " << span.shortestSpan() << std::endl;
	std::cout << "example longest: " << span.longestSpan() << std::endl;
}

static void testRange()
{
	std::vector<int> values;
	Span span(5);

	values.push_back(6);
	values.push_back(3);
	values.push_back(17);
	values.push_back(9);
	values.push_back(11);
	span.addNumbers(values.begin(), values.end());
	std::cout << "range shortest: " << span.shortestSpan() << std::endl;
	std::cout << "range longest: " << span.longestSpan() << std::endl;
}

static void testExceptions()
{
	Span full(2);

	full.addNumber(1);
	full.addNumber(2);
	try
	{
		full.addNumber(3);
	}
	catch (const std::exception& error)
	{
		std::cout << "full: " << error.what() << std::endl;
	}
	try
	{
		Span empty(2);
		empty.shortestSpan();
	}
	catch (const std::exception& error)
	{
		std::cout << "empty: " << error.what() << std::endl;
	}
}

static void testLargeInput()
{
	std::vector<int> values;
	Span span(10000);
	int number;

	for (number = 0; number < 10000; ++number)
		values.push_back(number * 3);
	span.addNumbers(values.begin(), values.end());
	std::cout << "10000 numbers shortest: " << span.shortestSpan() << std::endl;
	std::cout << "10000 numbers longest: " << span.longestSpan() << std::endl;
}

int main()
{
	testExample();
	testRange();
	testExceptions();
	testLargeInput();
	return 0;
}