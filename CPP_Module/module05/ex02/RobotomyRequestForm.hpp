#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& _target);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		virtual ~RobotomyRequestForm();

		void execute(const Bureaucrat &executor) const;
		
		class RobotomizeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};