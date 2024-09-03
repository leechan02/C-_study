#include "AForm.hpp"

AForm::AForm()
	: name("default"), gradeToSign(150), gradeToExecute(150), isSigned(0) {}

AForm::AForm(const std::string& _name, int _gradeToSign, int _gradeToExecute)
	: name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	isSigned = false;
}

AForm::AForm(const AForm& copy)
	: name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute), isSigned(copy.isSigned) {}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		isSigned = obj.isSigned;
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return (name);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form Exception: Form not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "Form " << obj.getName() << " is " << (obj.getIsSigned() ? "signed" : "not signed") << std::endl;
	out << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	out << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	return (out);
}