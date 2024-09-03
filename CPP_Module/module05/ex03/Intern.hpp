#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		AForm *makeForm(std::string name, std::string target);
		AForm *makeShrubberyCreationForm(std::string name);
		AForm *makeRobotomyRequestForm(std::string name);
		AForm *makePresidentialPardonForm(std::string name);

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};