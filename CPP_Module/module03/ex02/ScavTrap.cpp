#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	name = "default";
	HitPoints = SCAVHIT;
	EnergyPoints = SCAVENG;
	AttackDamage = SCAVATT;
	std::cout << GREEN << "ScavTrap Default constructor called"
	          << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	HitPoints = SCAVHIT;
	EnergyPoints = SCAVENG;
	AttackDamage = SCAVATT;
	std::cout << GREEN << "ScavTrap " << name << " constructor called"
	          << RESET << std::endl;}

ScavTrap::ScavTrap(const ScavTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << GREEN << "ScavTrap " << name << " copy constructor called"
	          << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << GREEN << "SvacTrap" << name << " copy assigment operator called" 
	          << RESET << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap " << name << " destructor called"
	          << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
		          << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ScavTrap " << name << " is trying to attak but " 
		          << name << " is die" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode"
		          << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " is trying to turn Gate keeper mode but " 
		          << name << " is die" << std::endl;
}