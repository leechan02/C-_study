/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:47:53 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/18 19:12:49 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setname(std::string nm);
};

Zombie*	zombieHorde(int N, std::string name);