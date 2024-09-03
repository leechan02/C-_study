#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
	: AForm("PresidentialPardonForm", 25, 5), target(_target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		target = copy.target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), target(copy.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::PresidentialPardonException::what() const throw()
{
	return ("PresidentialPardonException: pardon failed");
}