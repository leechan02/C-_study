#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		template <typename T>
		static T convert(std::string literal)
		{
			if (literal[literal.length() - 1] == 'f' && getTypes(literal) == "float")
				literal = literal.substr(0, literal.length() - 1);
			std::istringstream ss(literal);
			T value;

			ss >> value;
			if (ss.fail())
				throw UnknownLiteralException();
			return value;
		}
		class UnknownLiteralException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		static std::string getTypes(const std::string& literal);
};