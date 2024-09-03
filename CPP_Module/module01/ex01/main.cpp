/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:47:42 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/18 19:12:22 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie*	group = zombieHorde(7, "zomebie");
	
	for (int i = 0; i < 7; i++)
		group[i].announce();
	delete []group;
	return (0);
}