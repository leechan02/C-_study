#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExecute;
		bool isSigned;
	public:
		Form();
		Form(const std::string& _name, int _gradeToSign, int _gradeToExecute);
		Form(const Form& copy);
		Form& operator=(const Form& obj);
		~Form();

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& obj);