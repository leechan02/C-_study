#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongCat(void);
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& obj);
		~WrongCat(void);
		void makeSound(void) const;
		std::string getType(void) const;
};
