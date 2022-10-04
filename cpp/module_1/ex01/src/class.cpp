#include "../phone_book.hpp"

/*mes constructeur*/
Contact::Contact()
{
	
}

PhoneBook::PhoneBook()
{
	
}

void	Contact::add()
{
	std::cout << "Entre le prenom(first name)";
	std::cin >> this->first_name; >> std::endl;
}

/*
 *	fonction de class 
 *
int	Personnage::up_test(int &test)
{
	test += 2;	
	return (test);
}*/
