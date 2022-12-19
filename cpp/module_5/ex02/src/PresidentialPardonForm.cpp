#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "Default constructor call for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
	*this = src;
	std::cout << "Copy constructor call for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default destuctor call for PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "Default assignement constructor call for PresidentialPardonForm" << std::endl;
	(void)src;
	return *this;
}

void	PresidentialPardonForm::action(std::string target) const
{
	std::cout << target << " has been forgiven by the Zaphod Beeblebrox." << std::endl;
}
