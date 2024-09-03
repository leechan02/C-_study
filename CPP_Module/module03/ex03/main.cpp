#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "===DiamondTrap test===" << std::endl;
	{
		DiamondTrap d;

		d.whoAmI();
		d.attack("A");
	}
	return 0;
}