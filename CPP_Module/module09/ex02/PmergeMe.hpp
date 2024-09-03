#pragma once

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <list>
#include <ctime>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

typedef std::pair<int, int>	t_pair;

template <typename T, template<typename, typename = std::allocator<T> > class Container = std::vector>
class PmergeMe
{
	private:
		Container<T> container;
	public:
		PmergeMe() : container() {};
		PmergeMe(PmergeMe const &other) : container(other.container) {};
		PmergeMe &operator=(PmergeMe const &other)
		{
			if (this != &other)
				container = other.container;
			return *this;
		};
		~PmergeMe() {};

		void parseArgs(int ac, char **av)
		{
			int convert;
			std::stringstream ss;

			for (int i = 1; i < ac; i++)
			{
				ss << av[i];
				if (!(ss >> convert) || ss.peek() != EOF || convert < 0)
					throw std::invalid_argument("Error");
				container.push_back(convert);
				ss.clear();
			}
		};
		void printContainer() const
		{
			for (typename Container<T>::const_iterator it = container.begin(); it != container.end(); it++)
				std::cout << *it << " ";
		};
		Container<T> &getContainer()
		{
			return container;
		};
};

struct t_pend
{
	t_pend(int num, std::list<int>::iterator iter)
	{
		this->num = num;
		this->iter = iter;
	}
	int	num;
	std::list<int>::iterator	iter;
};