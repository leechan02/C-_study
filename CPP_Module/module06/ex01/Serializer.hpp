#pragma once

#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

struct Data
{
	std::string s;
	int n;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};