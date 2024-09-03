/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:55:58 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/20 13:47:57 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &wp)
{
	weapon = &wp;
}

void	HumanB::attack(void)
{
	if (!weapon)
		return ;
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
