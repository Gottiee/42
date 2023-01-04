#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
class Form;
#include "Bureaucrat.hpp"

class Form
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Form(std::string name, int sign, int exec);
	Form(Form const &src);
	~Form();
	Form		&operator=(Form const &src);
	int			beSigned(Bureaucrat &bur);
	int			getGrade(void) const;
	int			getGradeExec(void) const;
	std::string	getName(void) const;
	bool		getSign(void) const;

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
	Form();
	std::string _name;
	int			_gradeSign;
	int			_gradeExec;
	bool		_sign;
};

std::ostream	&operator<<(std::ostream& os, Form const &src);

#endif
