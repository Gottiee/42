# include "../phone_book.hpp"

void	print_instruction(void)
{
	std::cout << "COMMANDES:" << std::endl << std::endl;
	std::cout << "\"ADD\" 		:ajoute un contact a la liste." << std::endl;
	std::cout << "\"SEARCH\"	:affiche les contacts." << std::endl;	
	std::cout << "\"EXIT\"		:quitte le programme et supprime les contactes." << std::endl << std::endl;
}

int main(void)
{
	std::string cin;
	std::string add("ADD");
	std::string search("SEARCH");
	std::string exit("EXIT");
	PhoneBook phoneBook;

	cin.erase();
	while (cin != exit)
	{
		print_instruction();
		std::cout << "PhoneBook: ";
		std::cin >> cin;
		if (cin == add)
			phoneBook.add_conctact();
		if (cin == search)
			phoneBook.search_contact();
	}
	return (0);
}
