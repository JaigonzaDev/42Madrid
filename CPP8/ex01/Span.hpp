#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <cstddef>
# include <exception>
# include <iterator>
# include <vector>

class Span
{
public:
	Span(unsigned int maximumSize);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		std::size_t count = std::distance(begin, end);

		if (_numbers.size() + count > _maximumSize)
			throw SpanFullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class SpanFullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	std::vector<int> _numbers;
	unsigned int _maximumSize;
};

#endif