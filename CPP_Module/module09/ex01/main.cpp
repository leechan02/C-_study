#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"2 4 * 5 + \"" << std::endl;
		return 1;
	}
	RPN rpn;

	try
	{
		rpn.parse(av[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
