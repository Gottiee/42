#include "../header/Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> test(4);
	Array<std::string> test_char(2);
	Array<float> void_test;

	test[0] = 66;
	test[1] = 0;
	test[2] = 14;
	test[3] = 20;

	test_char[0] = "nice";
	test_char[1] = "one";

	std::cout << "size of test Array<int>: " << test.size() << std::endl;
	std::cout << "print of value:\n";

	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << std::endl;

	std::cout << "\nsize of test_char : "<< test_char.size() << std::endl;
	std::cout << "print test_char value:\n";
	std::cout << test_char[0] << " " << test_char[1] << std::endl;
	std::cout << "\nTesting print void_test[0]\n";
	try
	{
		std::cout << void_test[0] << std::endl;
	}
	catch(sizePro &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nTesting print test_char[20]\n";
	try
	{
		std::cout << test_char[20] << std::endl;
	}
	catch(sizePro &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nsize of void_test : " << void_test.size() << std::endl;

	std::cout << "\nCopy test\n\n";
	Array<int> copy(test);
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	std::cout << "\nModified value of copy print it, then print original class to check if it doesn't been changed\n";

	copy[0] = 52;
	copy[1] = 500;
	copy[2] = 545;
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;
	
	for (unsigned int i = 0; i < test.size(); i++)
		std::cout << test[i] << " ";
	std::cout << std::endl;
	return (0);
}
