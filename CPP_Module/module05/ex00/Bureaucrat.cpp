#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		grade = obj.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade < 2)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade > 149)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}