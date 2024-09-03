#pragma once

#include "Animal.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		~Brain(void);
};