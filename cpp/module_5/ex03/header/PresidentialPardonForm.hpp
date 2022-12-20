#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);
	virtual void	action(std::string target) const;

	private:
	PresidentialPardonForm();

};

#endif
