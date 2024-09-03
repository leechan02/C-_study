#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void leaks(void)
{
	system("leaks a.out | grep 'leaks for'");
}

int main(void)
{
	atexit(leaks);
	std::cout << GREEN << "=== Intern tests ===" << RESET << std::endl;
	{
		Intern someRandomIntern;
		Bureaucrat a("euiclee", 1);
		AForm* rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		try
		{
			a.signForm(*rrf);
			rrf->execute(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete rrf;
	}
	return 0;
}
