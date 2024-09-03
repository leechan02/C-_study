/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:38:39 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/19 10:54:07 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "\033[31m" << "memory address:" << "\033[0m" << std::endl;
	std::cout << std::setw(11) << "str: " << &str << std::endl;
	std::cout << std::setw(11) << "stringPTR: " << &stringPTR << std::endl;
	std::cout << std::setw(11) << "stringREF: " << &stringREF << std::endl;

	std::cout << "\033[32m" << "string variable:" << "\033[0m" << std::endl;
	std::cout << std::setw(11) << "str: " << str << std::endl;
	std::cout << std::setw(11) << "stringPTR: " << *stringPTR << std::endl;
	std::cout << std::setw(11) << "stringREF: " << stringREF << std::endl;
}