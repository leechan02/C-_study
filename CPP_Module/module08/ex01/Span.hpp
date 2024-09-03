#pragma once

#include <iostream>
#include <set>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Span
{
	private:
		unsigned int	size;
		std::set<int>	set;

	public:
		Span(unsigned int size = 0);
		Span(const Span &copy);
		~Span();
		
		Span &operator=(const Span &copy);
		
		void addNumber(int number);
		void addNumber(int *begin, int *end);
		
		int shortestSpan();
		int longestSpan();
		
		int getSet(int index);
		class FullArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};