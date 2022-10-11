#include "../phone_book.hpp"

/*constructeur*/
Contact::Contact()
{
	
}

/*prends la string et la print selon la norme du tableau*/
void	print_this_str(std::string str)
{
	int size;

	size = str.size();
	std::cout << " ";
	if (size < 10)
	{
		std::cout << str;
		while (size <= 11)
		{
			std::cout << " ";
			size ++;
		}
		std::cout << "|";
	}
	else 
		std::cout << str.substr(0, 9) << ". |";
}

/*print le tableau du contact[x]*/
void	Contact::print_contact(int index)
{
	std::cout << "| " << index << "          |";
	print_this_str(this->first_name);
	print_this_str(this->last_name);
	print_this_str(this->nick_name);
	std::cout << std::endl;
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
