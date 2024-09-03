/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:18:15 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/24 09:53:59 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl complains;

	if (ac == 2)
		complains.complain(av[1]);
	else
		std::cerr << "wrong aguments" << std::endl;
	return (0);
}