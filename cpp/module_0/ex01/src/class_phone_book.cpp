#include "../phone_book.hpp"

/*constructeur*/
PhoneBook::PhoneBook(): nbr_of_contact(0)
{

}

/*print la ligne du tableau*/
void	print_line(void)
{
	int i = -1;

	while (++i < 53)
		std::cout << "_";
	std::cout << std::endl;
}

void	print_mid_entete(void)
{
	std::cout << "| INDEX      | FIRST NAME | LAST NAME  | NICKNAME   |";
	std::cout << std::endl;
}

/*print l'entete du tableau de SEARCH*/
void	print_entete(void)
{
	int i = -1;
	int k = -1;
	//print le haut du tab
	while (++ k < 5)
	{
		std::cout << "|";
		while (++i < 12)
			std::cout << " ";
		i = -1;
	}
	std::cout << std::endl;
}

/*print du choix de l'indice*/
int	index_choose(int nbr_of_contact)
{
	std::string user_input;
	std::getline(std::cin, user_input);
	char	nbr = nbr_of_contact + 47;

	while (1)
	{
		std::cout << std::endl << "> ENTRER L'INDICE DU CONTACTE SOUHAITE: ";
		std::getline(std::cin, user_input);
		if (user_input == "")
			std::cout << "!! ANSWER NECESSARY !!" << std::endl;
		else if (user_input.size() > 1 || user_input.c_str()[0] < '0'
			|| user_input.c_str()[0] > nbr)
			std::cout << "Wrong Input ! Try again !" << std::endl;
		if (std::cin.eof())
			return (-1);
		else 
			break ;
	}
	return (std::atoi(user_input.c_str()));

}

/*afficher les contactes*/
void	PhoneBook::search_contact(void)
{
	int i = -1;
	int user_index;

	if (!this->nbr_of_contact)	
	{
		std::cout << std::endl << " > Vous avez aucun contact, \"ADD\" first !" << std::endl << std::endl;
		return ;
	}
	print_line();
	print_entete();
	print_mid_entete();
	print_entete();
	print_line();
	while (++i < this->nbr_of_contact)
	{
		this->contact[i].print_contact(i);
		print_line();
	}
	user_index = index_choose(this->nbr_of_contact);
	if (user_index == -1)
		return ;
	std::cout << std::endl << "CONTACT " << user_index << ":" << std::endl << std::endl;
	this->contact[user_index].print_search_contact();

}

void	PhoneBook::add_conctact(void)
{
	if (this->nbr_of_contact !=8)
		this->nbr_of_contact += 1;
	if (this->contact[this->nbr_of_contact - 1].add() == -1)
		return ;
}
