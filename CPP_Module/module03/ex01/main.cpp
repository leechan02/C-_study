#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "===virtual function test===" << std::endl;
	{
		ClapTrap* a_ptr = new ScavTrap("euiclee");

		a_ptr->attack("A");
		delete a_ptr;
	}
	return 0;
}