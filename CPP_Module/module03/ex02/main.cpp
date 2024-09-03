#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "===virtual function test===" << std::endl;
	{
		ScavTrap c("C");
		ClapTrap* a_ptr = &c;

		c.attack("A");
		a_ptr->attack("A");
	}
	std::cout << "===fragtrap test===" << std::endl;
	{
		FragTrap f("Me");
		f.highFivesGuys();
	}
	return 0;
}