#include "../phone_book.hpp"

/*constructeur*/
PhoneBook::PhoneBook(): nbr_of_contact(0)
{

}

/*afficher les contactes*/
void	PhoneBook::search_contact(void)
{
	int i = -1;

	if (!this->nbr_of_contact)	
	{
		std::cout << std::endl << " > Vous avez aucun contact, \"ADD\" first !" << std::endl << std::endl;
		return ;
	}
	//print l'entete avec les indications (index, first name, last, nick);
	// print le haut du tableau ---
	while (++i < this->nbr_of_contact)
	{
		this->contact[i].print_contact(i);
		//print la ligne du dessous a chaque fois
	}
}

void	PhoneBook::add_conctact(void)
{
	this->contact[this->nbr_of_contact].add();
	if (this->nbr_of_contact != 8)
		this->nbr_of_contact += 1;
}
