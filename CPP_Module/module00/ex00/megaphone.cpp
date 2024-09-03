/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:06:51 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/17 16:54:04 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	i,j;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (i = 1; i < ac; i++)
		for (j = 0; av[i][j]; j++)
			std::cout << static_cast<char>(toupper(av[i][j]));
	std::cout << std::endl;
	return (0);
}
