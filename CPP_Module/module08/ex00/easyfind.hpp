#pragma once

#include <iostream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class NotFoundException : public std::exception
{
	virtual const char *what() const throw()
	{
		return "failed to find the element";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == n)
			return it;
	}
	throw NotFoundException();
}
