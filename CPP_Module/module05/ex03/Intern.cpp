#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"shrubbery creation","robotomy request","presidential pardon"};
	typedef AForm* (Intern::*Form)(std::string target);
	Form form[3] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << target << std::endl;
			return (this->*form[i])(name);
		}
	}
	throw Intern::FormNotFoundException();
}

AForm *Intern::makeShrubberyCreationForm(std::string name)
{
	return new ShrubberyCreationForm(name);
}

AForm *Intern::makeRobotomyRequestForm(std::string name)
{
	return new RobotomyRequestForm(name);
}

AForm *Intern::makePresidentialPardonForm(std::string name)
{
	return new PresidentialPardonForm(name);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}