#include <iostream>

int main(void)
{
	// real string
	std::string	str("HI THIS IS BRAIN");
	// pointer to the string
	std::string *stringPTR = &str;
	// reference to the string
	std::string &stringREF = str;

	std::cout << "Memory of str: " << &str << std::endl;
	std::cout << "Memory of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory of stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl << std::endl;
}
