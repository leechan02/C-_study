#include "ScalarConverter.hpp"

template <typename T>
void print(T value)
{
	std::cout << "char: ";
	try
	{
		if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
			throw std::exception();

		char c = static_cast<char>(value);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
			throw std::exception();
		std::cout << static_cast<int>(value) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	std::cout << static_cast<float>(value);
	if (static_cast<float>(value) - static_cast<int>(value) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: ";
	std::cout << static_cast<double>(value);
	if (static_cast<double>(value) - static_cast<int>(value) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (1);
	}
	try
	{
		std::string type = ScalarConverter::getTypes(av[1]);
		if (type == "char")
			print(ScalarConverter::convert<char>(av[1]));
		else if (type == "int")
			print(ScalarConverter::convert<int>(av[1]));
		else if (type == "float")
			print(ScalarConverter::convert<float>(av[1]));
		else if (type == "double")
			print(ScalarConverter::convert<double>(av[1]));
		else
			std::cout << "Unknown type" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}