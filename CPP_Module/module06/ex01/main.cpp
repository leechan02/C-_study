#include "Serializer.hpp"

int main (void)
{
	Data *data = new Data;
	Data *data2;
	uintptr_t ptr;

	data->s = "Hello, world!";
	data->n = 42;

	std::cout << GREEN << "=== address test ==="<< RESET << std::endl;
	std::cout << "Data: " << data->s << " " << data->n << std::endl;
	std::cout << "Data address: " << data << std::endl;
	ptr = Serializer::serialize(data);
	data2 = Serializer::deserialize(ptr);
	std::cout << "Data2: " << data2->s << " " << data2->n << std::endl;
	std::cout << "Data2 address: " << data2 << std::endl;

	delete data;
	return 0;
}