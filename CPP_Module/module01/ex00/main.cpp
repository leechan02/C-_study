/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:21:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/18 18:43:34 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie*	heap = newZombie("heap");
	
	heap->announce();
	randomChump("FuncStack");
	delete heap;
	return (0);
}