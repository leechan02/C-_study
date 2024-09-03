#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << RED << "=== Bureaucrat init error===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("euiclee", 0);
		std::cout << euiclee;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << RED << "=== Bureaucrat High error===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("euiclee", 1);
		std::cout << euiclee;
		euiclee.incrementGrade();
		std::cout << euiclee;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << RED << "=== Bureaucrat Low error===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("euiclee", 150);
		std::cout << euiclee;
		euiclee.decrementGrade();
		std::cout << euiclee;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN << "=== Bureaucrat Normal===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("euiclee", 7);
		std::cout << euiclee;
		euiclee.incrementGrade();
		std::cout << euiclee;
		euiclee.decrementGrade();
		std::cout << euiclee;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
