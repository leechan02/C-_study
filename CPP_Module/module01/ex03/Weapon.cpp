/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:55:37 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/20 10:47:00 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType(void) const
{
	return (type);
}

void	Weapon::setType(std::string ty)
{
	type = ty;
}