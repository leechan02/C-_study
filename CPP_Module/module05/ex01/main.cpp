#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << RED << "=== Form exception test===" << RESET << std::endl;
	try
	{
		Form form("Secret", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << GREEN << "=== Form normal test===" << RESET << std::endl;
	try
	{
		Form form("Secret", 1, 1);
		Bureaucrat a("euiclee", 1);
		Bureaucrat b("lee", 150);

		std::cout << a;
		std::cout << b << std::endl;

		std::cout << form << std::endl;
		b.signForm(form);
		a.signForm(form);
		std::cout << std::endl << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
