/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:19:02 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/12 14:07:24 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		int		index, flag;
	public:
		void	add();
		void	search();
		void	openbook();
		void	finduser();
		PhoneBook();
};