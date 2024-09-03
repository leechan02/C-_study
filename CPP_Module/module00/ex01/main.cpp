/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:18:37 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/17 16:58:22 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	to_num(std::string str)
{
	std::istringstream	tmp(str);
	int					num;

	tmp >> num;
	if (tmp.fail())
		return (-1);
	return (num);
}

void	getcmd(std::string &buf, std::string msg, std::string color)
{
	while (true)
	{
		std::cout << color << msg << RESET;
		std::getline(std::cin, buf);
		if (!std::cin.good())
			exit (1);
		else if (buf == "")
		{
			std::cerr << RED << "You must enter cmd" << RESET << std::endl;
			continue ;
		}
		else
			break ;
	}
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	book;

	while (true)
	{
		getcmd(cmd, "Pls enter cmd: ", GREEN);
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cerr << RED << "Wrong cmd: " << RESET
					<< "(ADD, SEARCH, EXIT)" << std::endl;
	}
	return (0);
}