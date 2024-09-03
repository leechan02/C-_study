#pragma once

#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}