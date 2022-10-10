#include "../phone_book.hpp"

/*constructeur*/
Contact::Contact()
{
	
}

/*print le tableau du contact[x]*/
void	Contact::print_contact(int index)
{
	int i = -1;

	//print index
	std::cout << "| " << index << "          |";

	//print lastname (verif si c'est plus grand que 9 si non pprint puis comleter de la taille, si oui print que 9 et ecrire point)
	std::cout << "| ";
	if (this->last_name.size < 10)
	{
		std::cout << 
	}
}

/*ajouter un contacte*/
void	Contact::add()
{
	int loop = 0;
	std::getline(std::cin, this->first_name);

	while (loop != -1)
	{
		if (loop == 0)	
		{
			std::cout << "> Entrez le prenom(first name): ";
			std::getline(std::cin, this->first_name);
			if (this->first_name != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 1)
		{
			std::cout << "> Entrez le nom(last name): ";
			std::getline(std::cin, this->last_name);
			if (this->last_name != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 2)
		{
			std::cout << "> Entrez le surnom(nickname): ";
			std::getline(std::cin, this->nick_name);
			if (this->nick_name != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 3)
		{
			std::cout << "> Entrez le numero de telephone(phone number): ";
			std::getline(std::cin, this->phone_number);
			if (this->phone_number != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 4)
		{
			std::cout << "> Entrez son plus sombre secret(darkest secret): ";
			std::getline(std::cin, this->darkest_secret);
			if (this->darkest_secret != "")
				loop = -1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
	}
	std::cout << std::endl << "Enregristement Termine" << std::endl << std::endl;
}
