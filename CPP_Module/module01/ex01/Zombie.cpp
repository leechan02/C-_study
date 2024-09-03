/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:48:02 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/18 19:09:20 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::~Zombie(void)
{
	std::cout << name << " is die" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << " is awake" << std::endl;
}

void	Zombie::setname(std::string nm)
{
	name = nm;
}