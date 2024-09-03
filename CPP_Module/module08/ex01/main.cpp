#include "Span.hpp"
#include <vector>
#include <fstream>

int main()
{
	std::cout << GREEN << "=== main test ===" << RESET << std::endl;
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << GREEN << "=== error test ===" << RESET << std::endl;
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		try
		{
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	std::cout << GREEN << "=== 10,000 test ===" << RESET << std::endl;
	{
		std::srand(std::time(NULL));
		std::vector<int> ran_num(10000);
		for (int i = 0; i < 10000; i++)
			ran_num[i] = std::rand();
		
		Span sp = Span(10000);
		sp.addNumber(ran_num.data(), ran_num.data() + 10000);

		std::ofstream ofs("result.txt");
		for (int i = 0; i < 10000; i++)
			ofs << sp.getSet(i) << std::endl;
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	
	return 0;
}