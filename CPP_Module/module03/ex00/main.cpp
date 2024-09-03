#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(10);
	b.beRepaired(10);
	return 0;
}