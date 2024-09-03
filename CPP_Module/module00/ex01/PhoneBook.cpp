/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:06:22 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/17 10:19:40 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), flag(0){}

void	PhoneBook::add()
{
	if (index == 8)
		index = 0, flag = 1;
	contact[index].set("first");
	contact[index].set("last");
	contact[index].set("nick");
	contact[index].set("number");
	contact[index].set("secret");
	index++;
}

void	PhoneBook::search()
{
	openbook();
	finduser();
}

void	PhoneBook::openbook()
{
	std::cout << "===================Contact===================" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;
	if (flag == 1)
		for (int i = 0; i < 8; i++)
			contact[i].list(i);
	else
		for (int i = 0; i < index; i++)
			contact[i].list(i);
	std::cout << "=============================================" << std::endl;
}

void	PhoneBook::finduser()
{
	std::string num;
	int			_num;

	while (true)
	{
		getcmd(num, "Enter index number : ", BLUE);
		if (num.size() == 1)
			_num = to_num(num);
		if (num.size() > 1 || !(_num >= 0 && _num < 8) || (flag == 0 && _num >= index))
		{
			std::cout << RED << "Wrong index!" << RESET << std::endl;
			return ;
		}
		else
			break ;
	}
	std::cout << "first name is : ";
	contact[_num].get("first");
	std::cout << "last name is : ";
	contact[_num].get("last");
	std::cout << "nickname : ";
	contact[_num].get("nick");
	std::cout << "phone_number : ";
	contact[_num].get("number");
	std::cout << "darkest_secret : ";
	contact[_num].get("secret");
}