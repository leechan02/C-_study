#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	name = "default";
	HitPoints = FRAGHIT;
	EnergyPoints = FRAGENG;
	AttackDamage = FRAGATT;
	std::cout << GREEN << "FragTrap Default constructor called"
	          << RESET << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	HitPoints = FRAGHIT;
	EnergyPoints = FRAGENG;
	AttackDamage = FRAGATT;
	std::cout << GREEN << "FragTrap " << name << " constructor called"
	          << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << GREEN << "FragTrap " << name << " copy constructor called"
	          << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << GREEN << "SvacTrap" << name << " copy assigment operator called" 
	          << RESET << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << "FragTrap " << name << " destructor called"
	          << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		std::cout << "High fives! FragTrap " << name << "!"
		          << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " is trying to turn Gate keeper mode but " 
		          << name << " is die" << std::endl;
}