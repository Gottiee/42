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
	Form();
	Form(std::string name, int sign, int exec);
	Form(Form const &src);
	virtual			~Form();
	Form			&operator=(Form const &src);
	int				beSigned(Bureaucrat &bur);
	int				getGrade(void) const;
	int				getGradeExec(void) const;
	std::string		getName(void) const;
	bool			getSign(void) const;
	void			setName(std::string);
	void			setGradeSign(int);
	void			setGradeExec(int);
	void			setSign(bool);
	virtual void	action(std::string target) const = 0;
	void			execute(Bureaucrat const &executor) const;

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
	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	protected:
	std::string _target;

	private:
	std::string _name;
	int			_gradeSign;
	int			_gradeExec;
	bool		_sign;
};

std::ostream	&operator<<(std::ostream& os, Form const &src);

#endif
