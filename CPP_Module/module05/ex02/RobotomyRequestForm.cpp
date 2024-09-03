#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target)
	: AForm("RobotomyRequestForm", 72, 45), target(_target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		target = copy.target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;

	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		throw RobotomizeException();
}

const char* RobotomyRequestForm::RobotomizeException::what() const throw()
{
	return ("RobotomizeException: robotomize failed");
}