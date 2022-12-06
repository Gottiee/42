#include "../header/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor call for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	std::cout << "Copy constructor call for Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default destuctor call for Bureaucrat" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Default assignement call for Bureaucrat" << std::endl;	return *this;

}

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade << ".";
	return (os);
}
