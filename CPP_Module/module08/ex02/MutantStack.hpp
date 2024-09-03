#pragma once

#include <iostream>
#include <stack>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
		MutantStack<T> &operator=(const MutantStack<T> &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {return std::stack<T>::c.begin();}
		iterator end() {return std::stack<T>::c.end();}
};