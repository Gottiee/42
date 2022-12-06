#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();
	Bureaucrat	&operator=(Bureaucrat const &src);
	std::string	getName(void) const;
	int			getGrade(void) const;

	private:
	std::string _name;
	int			_grade;
};

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &src);

#endif
