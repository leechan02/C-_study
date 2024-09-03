#include "PmergeMe.hpp"
#include "FordJohnsonVector.hpp"
#include "FordJohnsonList.hpp"
#include <iomanip>

void SortCompare(int ac, char **av)
{
	clock_t start, end;

	// std::vector
	start = clock();
	PmergeMe<int> vector;

	vector.parseArgs(ac, av);
	FordJohnson(vector.getContainer());
	end = clock();

	std::cout << "After: ";
	vector.printContainer();
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vector.getContainer().size()
				<< " elements with std::vector : " << std::fixed << std::setprecision(3)
				<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;

	// std::list
	start = clock();
	PmergeMe<int, std::list> list;

	list.parseArgs(ac, av);
	FordJohnson(list.getContainer());

	end = clock();
	std::cout << "Time to process a range of " << list.getContainer().size()
				<< " elements with std::list : " << std::fixed << std::setprecision(3)
				<< static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
}

int main(int ac, char **av)
{
	if (ac > 2)
	{
		try
		{
			PmergeMe<int> parse;

			parse.parseArgs(ac, av);

			std::cout << "Before: ";
			parse.printContainer();
			std::cout << std::endl;
			SortCompare(ac, av);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: " << av[0] << " [arg1] [arg2] ..." << std::endl;
	return 0;
}