#include "../header/PresidentialPardonForm.hpp"

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
	return *this;

}