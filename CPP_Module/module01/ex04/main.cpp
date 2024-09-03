/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:35:43 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/21 17:22:42 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "wrong arguments" << std::endl;
		return (1);
	}
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream in(file);
	std::ofstream out(file + ".replace");
	std::string line;
	size_t pos;

	if (in.is_open() && out.is_open())
	{
		while (!in.eof())
		{
			pos = 0;
			std::getline(in, line);
			while (pos < line.length())
			{
				pos = line.find(s1, pos);
				if (pos == std::string::npos)
					break ;
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
			out << line;
			if (!in.eof())
				out << std::endl;
		}
	}
	else
		std::cerr << "open error" << std::endl;
	return (0);
}
