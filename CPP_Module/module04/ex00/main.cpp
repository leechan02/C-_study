#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "===Animal test===" << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete i;
		delete j;
		delete meta;
	}
	std::cout << "===WrongAnimal test===" << std::endl;
	{
		const WrongAnimal* a = new WrongCat();

		std::cout << a->getType() << " " << std::endl;

		a->makeSound();
		delete a;
	}
	return 0;
}