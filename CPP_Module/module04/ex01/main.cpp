#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void leaks(void)
{
	system("leaks a.out | grep 'leaks for'");
}

int main(void)
{
	atexit(leaks);
	std::cout << "===Normal test===" << std::endl;
	{
		const Animal* i = new Dog();
		const Animal* j = new Cat();

		delete i;
		delete j;
	}
	std::cout << "===Brain test===" << std::endl;
	{
		int i = 0;
		Animal* animals[4];

		while (i < 2)
			animals[i++] = new Dog();
		while (i < 4)
			animals[i++] = new Cat();
		while (i > 0)
			delete animals[--i];
	}
	return 0;
}