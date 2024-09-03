/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:43:28 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/12 13:41:06 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::list(int i)
{
	std::cout << "|" << std::setw(10) << i << "|";
	if (first_name.size() > 10)
		std::cout << first_name.substr(0,9) << "." << "|";
	else
		std::cout << std::setw(10) << first_name << "|";
	if (last_name.size() > 10)
		std::cout << last_name.substr(0,9) << "." << "|";
	else
		std::cout << std::setw(10) << last_name << "|";
	if (nickname.size() > 10)
		std::cout << nickname.substr(0,9) << "." << "|" << std::endl;
	else
		std::cout << std::setw(10) << nickname << "|" << std::endl;
}

void	Contact::get(std::string value)
{
	if (value == "first")
		std::cout << first_name << std::endl;
	else if (value == "last")
		std::cout << last_name << std::endl;
	else if (value == "nick")
		std::cout << nickname << std::endl;
	else if (value == "number")
		std::cout << phone_number << std::endl;
	else if (value == "secret")
		std::cout << darkest_secret << std::endl;
}

void	Contact::set(std::string value)
{
	if (value == "first")
		getcmd(first_name, "first name is : ", RESET);
	else if (value == "last")
		getcmd(last_name, "last name is : ", RESET);
	else if (value == "nick")
		getcmd(nickname, "nickname : ", RESET);
	else if (value == "number")
		getcmd(phone_number, "phone_number : ", RESET);
	else if (value == "secret")
		getcmd(darkest_secret, "darkest_secret : ", RESET);
}
