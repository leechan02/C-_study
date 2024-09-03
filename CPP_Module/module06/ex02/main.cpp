#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case 0: 
			std::cout << "A generated" << std::endl;
			return (new A);
		case 1:
			std::cout << "B generated" << std::endl;
			return (new B);
		case 2:
			std::cout << "C generated" << std::endl;
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C pointer" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A reference" << std::endl;
		(void)a;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "B reference" << std::endl;
			(void)b;
		}
		catch (std::bad_cast &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "C reference" << std::endl;
				(void)c;
			}
			catch (std::bad_cast &e)
			{
				std::cout << "bad cast" << std::endl;
			}
		}
	}
}

int main(void)
{
	std::cout << GREEN << "=== downcast ===" << RESET << std::endl;
	{
		Base *base = generate();

		identify(base);
		identify(*base);
		delete base;
	}
	std::cout << RED << "=== downcast fail ===" << RESET << std::endl;
	{
		Base *base = new Base();

		identify(base);
		identify(*base);
		delete base;
	}

	return (0);
}