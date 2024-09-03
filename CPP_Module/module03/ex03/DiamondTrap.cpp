#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	name = "default";
	ClapTrap::name = "default_calp_name";
	HitPoints = FRAGHIT;
	EnergyPoints = SCAVENG;
	AttackDamage = FRAGATT;
	std::cout << GREEN << "DiamondTrap Default constructor called"
	          << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	ClapTrap::name = name + "_calp_name";
	HitPoints = FRAGHIT;
	EnergyPoints = SCAVENG;
	AttackDamage = FRAGATT;
	std::cout << GREEN << "DiamondTrap " << name << " constructor called"
	          << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << GREEN << "DiamondTrap " << name << " copy constructor called"
	          << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << GREEN << "DiamondTrap" << name << " copy assigment operator called" 
	          << RESET << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "DiamondTrap " << name << " destructor called"
	          << RESET << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << name
			  << " and ClapTrap name is " << ClapTrap::name << std::endl;
}
