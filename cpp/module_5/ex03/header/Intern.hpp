#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"

class Intern
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Intern();
	Intern(Intern const &src);
	~Intern();
	Intern	&operator=(Intern const &src);
	Form	*makeForm(std::string const &name, std::string const &target);

	private:
	typedef struct s_form
	{
		std::string	target;
		Form		*form;
	} t_form;
};

#endif
