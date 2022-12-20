#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();
	Bureaucrat	&operator=(Bureaucrat const &src);
	void		operator++ (int);
	void		operator-- (int);
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		signForm(Form &form);
	void		executeForm(Form const &form);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	
	private:
	Bureaucrat();
	std::string _name;
	int			_grade;

};

std::ostream	&operator<<(std::ostream& os, Bureaucrat const &src);

#endif
