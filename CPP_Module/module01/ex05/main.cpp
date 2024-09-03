/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:18:15 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/24 09:37:15 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl complains;

	complains.complain("debug");
	complains.complain("info");
	complains.complain("warning");
	complains.complain("error");
	return (0);
}