#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name("void"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << GREEN << name << " constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
	: name(src.name), HitPoints(src.HitPoints), EnergyPoints(src.EnergyPoints), AttackDamage(src.AttackDamage)
{
	std::cout << name << GREEN << " copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	name = src.name;
	HitPoints = src.HitPoints;
	EnergyPoints = src.EnergyPoints;
	AttackDamage = src.AttackDamage;
	std::cout << name << GREEN << " copy assigment operator called" << RESET << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << RED << name << " destructor called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		          << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << name << " is trying to attak but " 
		          << name << " is die" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " takes " << amount
		          << " points of damage!" << std::endl;
		HitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << name << " takes damage but " 
		          << name << " is already die" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints > 0 && EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << name << " be repaired " << amount
		          << " points of hp!" << std::endl;
		HitPoints += amount;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << name << " is trying to repair but " 
		          << name << " is already die" << std::endl;
}
