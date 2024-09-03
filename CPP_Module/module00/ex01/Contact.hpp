/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:43:37 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/12 13:12:41 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void	get(std::string value);
		void	set(std::string value);
		void	list(int i);
};