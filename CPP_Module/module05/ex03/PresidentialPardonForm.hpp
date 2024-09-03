#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& _target);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		virtual ~PresidentialPardonForm();

		void execute(const Bureaucrat &executor) const;
		
		class PresidentialPardonException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};