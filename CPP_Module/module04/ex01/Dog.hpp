#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;
	protected:
		std::string type;
	public:
		Dog(void);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		~Dog(void);
		void makeSound(void) const;
		std::string getType(void) const;
};
