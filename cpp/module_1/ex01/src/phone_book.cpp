# include "../phone_book.hpp"

void	print_instruction(void)
{
	std::cout << "COMMANDES:" << std::endl << std::endl;
	std::cout << "\"ADD\" 		:ajoute un contact a la liste." << std::endl;
	std::cout << "\"SEARCH\"	:affiche les contacts." << std::endl;	
	std::cout << "\"EXIT\"		:quitte le programme et supprime les contactes." << std::endl;
}

void	ft_add(void)
{		
}

int main(void)
{
	std::string cin;
	std::string add("ADD");
	std::string search("SEARCH");
	std::string exit("EXIT");
	Contact contact;

	print_instruction();
	cin.erase();
	while (cin != exit)
	{
		std::cin >> cin;
		if (cin == add)
			ft_add();
	/*if (cin == search)
			ft_search;*/	
	}
	return (0);
}
