/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:37:02 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/20 10:46:17 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string str);
		~Weapon();
		const std::string& getType(void) const;
		void setType(std::string ty);
};
