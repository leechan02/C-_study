#include "Form.hpp"

Form::Form()
	: name("default"), gradeToSign(150), gradeToExecute(150), isSigned(0) {}

Form::Form(const std::string& _name, int _gradeToSign, int _gradeToExecute)
	: name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	isSigned = false;
}

Form::Form(const Form& copy)
	: name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute), isSigned(copy.isSigned) {}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
		isSigned = obj.isSigned;
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade too low");
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << "Form " << obj.getName() << " is " << (obj.getIsSigned() ? "signed" : "not signed") << std::endl;
	out << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	out << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	return (out);
}
