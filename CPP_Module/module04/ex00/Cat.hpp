#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string type;
	public:
		Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		~Cat(void);
		void makeSound(void) const;
		std::string getType(void) const;
};
