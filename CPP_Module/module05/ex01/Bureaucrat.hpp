#pragma once

#include <iostream>
#include "Form.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& obj);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);