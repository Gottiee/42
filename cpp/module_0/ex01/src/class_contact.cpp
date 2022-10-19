#include "../phone_book.hpp"

/*constructeur*/
Contact::Contact()
{
	
}

void	Contact::print_search_contact(void)
{
	std::cout << "> FIRST NAME: " << this->first_name << std::endl;
	std::cout << "> LAST NAME: " << this->last_name << std::endl;
	std::cout << "> NICK NAME: " << this->nick_name << std::endl;
	std::cout << "> PHONE NUMBER: " << this->phone_number << std::endl;
	std::cout << "> DARKEST SECRET: " << this->darkest_secret << std::endl << std::endl;
	std::cout <<" END " << std::endl << std::endl;
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
		while (size <= 10)
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
int	Contact::add()
{
	int loop = 0;
	std::getline(std::cin, this->first_name);

	while (loop != -1)
	{
		if (loop == 0)	
		{
			std::cout << "> Entrer le prenom(first name): ";
			std::getline(std::cin, this->first_name);
			if (this->first_name != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 1)
		{
			std::cout << "> Entrer le nom(last name): ";
			std::getline(std::cin, this->last_name);
			if (this->last_name != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 2)
		{
			std::cout << "> Entrer le surnom(nickname): ";
			std::getline(std::cin, this->nick_name);
			if (this->nick_name != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 3)
		{
			std::cout << "> Entrer le numero de telephone(phone number): ";
			std::getline(std::cin, this->phone_number);
			if (this->phone_number != "")
				loop += 1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (loop == 4)
		{
			std::cout << "> Entrer son plus sombre secret(darkest secret): ";
			std::getline(std::cin, this->darkest_secret);
			if (this->darkest_secret != "")
				loop = -1;
			else 
				std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		}
		if (std::cin.eof())
			return (-1);
	}
	std::cout << std::endl << "Enregristement Termine" << std::endl << std::endl;
	return (0);
}
