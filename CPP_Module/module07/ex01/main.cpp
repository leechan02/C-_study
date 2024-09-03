#include "iter.hpp"

int main(void)
{
	std::cout << GREEN << "=== int ===" << RESET << std::endl;
	int int_array[] = { 1, 2, 3, 4, 5 };
	iter(int_array, 5, print);

	std::cout << GREEN << "=== string ===" << RESET << std::endl;
	std::string string_array[] = { "Hello", "World", "!" };
	iter(string_array, 3, print);

	std::cout << GREEN << "=== double ===" << RESET << std::endl;
	double double_array[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	iter(double_array, 5, print);
	return (0);
}