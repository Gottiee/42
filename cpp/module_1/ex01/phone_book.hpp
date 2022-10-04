#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <string>

class Contact
{
	public:

	Contact();
	void	add(void);

	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_numer;
	std::string darkest_secret;
};

class PhoneBook
{
	public:

	//declaration du constructeur qui sert a initialiser mes variables
	PhoneBook();
	
	private:
	Contact contact[8];
	//tableau de contacte ? 

};

#endif
