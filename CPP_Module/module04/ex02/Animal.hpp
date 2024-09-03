#pragma once

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual ~Animal(void);
		virtual void makeSound(void) const = 0;
		virtual std::string getType(void) const;
};
