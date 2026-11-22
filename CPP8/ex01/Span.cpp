#include "Span.hpp"

Span::Span(unsigned int maximumSize)
	: _numbers(), _maximumSize(maximumSize)
{
	_numbers.reserve(maximumSize);
}

Span::Span(const Span& other)
	: _numbers(other._numbers), _maximumSize(other._maximumSize)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maximumSize = other._maximumSize;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maximumSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	std::vector<int> sortedNumbers;
	std::vector<int>::const_iterator current;
	unsigned int shortest;

	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	shortest = static_cast<unsigned int>(sortedNumbers[1] - sortedNumbers[0]);
	for (current = sortedNumbers.begin() + 1; current != sortedNumbers.end(); ++current)
	{
		unsigned int span = static_cast<unsigned int>(*current - *(current - 1));
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	std::vector<int>::const_iterator minimum;
	std::vector<int>::const_iterator maximum;

	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	minimum = std::min_element(_numbers.begin(), _numbers.end());
	maximum = std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(*maximum - *minimum);
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate a span";
}