#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << GREEN << "=== ShrubberyCreationForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("Euiclee", 1);
		ShrubberyCreationForm shrubbery("home");

		// shrubbery.beSigned(euiclee);
		std::cout << shrubbery << std::endl;
		shrubbery.execute(euiclee);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN << "=== RobotomyRequestForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("Euiclee", 1);
		RobotomyRequestForm robotomy("home");

		robotomy.beSigned(euiclee);
		std::cout << robotomy << std::endl;
		robotomy.execute(euiclee);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << GREEN << "=== PresidentialPardonForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat euiclee("Euiclee", 1);
		PresidentialPardonForm pardon("home");

		pardon.beSigned(euiclee);
		std::cout << pardon << std::endl;
		pardon.execute(euiclee);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
