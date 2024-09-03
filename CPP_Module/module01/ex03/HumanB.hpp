/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:21:06 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/20 13:45:50 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &wp);
		void	attack(void);
};