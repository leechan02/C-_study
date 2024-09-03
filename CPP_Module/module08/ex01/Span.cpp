#include "Span.hpp"

Span::Span(unsigned int size) : size(size) {}

Span::Span(const Span &copy) : size(copy.size), set(copy.set) {}

Span::~Span() {}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		size = copy.size;
		set = copy.set;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (set.size() == size)
		throw FullArrayException();
	set.insert(number);
}

void Span::addNumber(int *begin, int *end)
{
	if (end - begin + set.size() > size)
		throw FullArrayException();
	set.insert(begin, end);
}

int Span::shortestSpan()
{
	if (set.size() <= 1)
		throw NotEnoughNumbersException();

	std::set<int>::iterator begin = set.begin();
	std::set<int>::iterator end = set.end();
	int shortest;

	--end;
	for (shortest = *end - *begin; begin != end; ++begin)
	{
		std::set<int>::iterator it = begin;
		++it;
		if (it != end && *it - *begin < shortest)
			shortest = *it - *begin;
	}
	return shortest;
}

int Span::getSet(int index)
{
	if (index < 0 || index >= (int)set.size())
		throw std::out_of_range("Index out of range.");
	std::set<int>::iterator it = set.begin();
	for (int i = 0; i < index; ++i)
		++it;
	return *it;
}

int Span::longestSpan()
{
	if (set.size() <= 1)
		throw NotEnoughNumbersException();
	return *(set.rbegin()) - *(set.begin());
}

const char *Span::FullArrayException::what() const throw()
{
	return "The array is full.";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers in the array.";
}
