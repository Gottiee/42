#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <string>

class Contact
{
	public:

	Contact();
	void	add(void);
	void	print_contact(int index);

	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string darkest_secret;
};

class PhoneBook
{
	public:

	//declaration du constructeur qui sert a initialiser mes variables
	PhoneBook();
	void	add_conctact();
	void	search_contact();
	
	private:
	Contact contact[8];
	int		nbr_of_contact;

};

#endif
