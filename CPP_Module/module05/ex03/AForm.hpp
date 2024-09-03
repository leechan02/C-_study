#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExecute;
		bool isSigned;
	public:
		AForm();
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &copy);
		virtual ~AForm();
		AForm &operator=(const AForm &copy);

		const std::string &getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;

		void beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);