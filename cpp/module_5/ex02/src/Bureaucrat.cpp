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

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Perso constructor call for Bureaucrat" << std::endl;
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Default assignement call for Bureaucrat" << std::endl;
	this->_name = src.getName();
	this->_grade = src.getGrade();
	return *this;

}

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (os);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to hight you can't be better than grade 1");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low you can't be more bad than grade 150");
}

void	Bureaucrat::operator--(int)
{
	this->_grade ++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::operator++(int)
{
	this->_grade --;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (form.getSign())
			throw std::exception();
		form.beSigned(*this);
		std::cout << this->_name << "sign " << form.getName()
		<< "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
		<< "because he is already sign." << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (Form::GradeTooLowException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Form::FormNotSignedException &e)
	{
        std::cerr << e.what() << std::endl;
	}
}
