#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
private:
	T *_data;
	std::size_t _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	~Array();

	Array &operator=(const Array &other);

	T &operator[](std::size_t index);
	const T &operator[](std::size_t index) const;

	std::size_t size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif
