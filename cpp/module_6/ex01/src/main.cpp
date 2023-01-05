#include "../header/main.hpp"

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data *data = new Data;
	uintptr_t	tmp;

	data->test = 2;
	data->test2 = "ahah bien joué ! ";
	std::cout << "Data filled: int = 2 | string = \"ahah bien joué\"\n";
	std::cout << data->test << std::endl;
	std::cout << data->test2<< std::endl;
	tmp = serialize(data);
	std::cout << "\nvalue of the uintptr_t after reinterpret cast: ";
	std::cout << tmp << std::endl;
	data = deserialize(tmp);
	std::cout << "\nValue after deserialize cast:\n";
	std::cout << data->test << std::endl;
	std::cout << data->test2<< std::endl;
	delete data;
}
