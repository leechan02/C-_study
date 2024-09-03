#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		std::cout << GREEN << "found: " << RESET << *easyfind(v, 3) << std::endl;
		std::cout << GREEN << "found: " << RESET << *easyfind(v, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return 0;
}
