#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

std::string ScalarConverter::getTypes(const std::string& literal)
{
	int f = 0;
	int point = 0;

	if (!literal.compare("-inff") || !literal.compare("+inff")
		|| !literal.compare("inff") || !literal.compare("nanf"))
		return ("float");
	else if (!literal.compare("-inf") || !literal.compare("+inf")
		|| !literal.compare("inf") || !literal.compare("nan"))
		return ("double");
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return ("char");
	else if (literal.length() == 1 && isalpha(literal[0]))
		return ("char");
	for (size_t i = 1; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			point++;
		else if (literal[i] == 'f')
			f++;
		else if (!isdigit(literal[i]))
			return ("unknown");
	}
	if (point > 1 || f > 1)
		return ("unknown");
	else if (point == 1 && f == 1)
		return ("float");
	else if (point == 1 && f == 0)
		return ("double");
	else
		return ("double");
}

const char* ScalarConverter::UnknownLiteralException::what() const throw()
{
	return ("Unknown literal");
}