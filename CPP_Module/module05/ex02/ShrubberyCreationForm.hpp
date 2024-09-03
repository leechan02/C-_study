#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& _target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		virtual ~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
		
		class FileOpenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};