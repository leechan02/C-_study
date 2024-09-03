/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:18:51 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/24 09:55:51 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
	          << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
	          << "I’ve been coming for years whereas you started working here since last month."
              << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	std::string messege[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void(Harl::*FuncPtr)(void);
	FuncPtr func[4]= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (i = 0; i < 4; i++)
		if (messege[i] == level)
			break ;
	switch (i)
	{
		case 0:
			(this->*func[i++])();
		case 1:
			(this->*func[i++])();
		case 2:
			(this->*func[i++])();
		case 3:
			(this->*func[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
