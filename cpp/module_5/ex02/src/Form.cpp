#include "../header/Form.hpp"

Form::Form()
{
	std::cout << "Default constructor call for Form" << std::endl;
}

Form::Form(std::string name, int sign, int exec): _name(name), _sign(false)
{
	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	this->_gradeSign = sign;
	this->_gradeExec = exec;
}

Form::Form(Form const &src)
{
	*this = src;
	std::cout << "Copy constructor call for Form" << std::endl;
}

Form::~Form()
{
	std::cout << "Default destuctor call for Form" << std::endl;
}

Form	&Form::operator=(Form const &src)
{
	std::cout << "Default assignement constructor call for Form" << std::endl;
	this->_gradeSign = src.getGrade();
	this->_gradeExec = src.getGradeExec();
	this->_sign = src.getSign();
	return *this;

}

std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getGrade() const
{
	return this->_gradeSign;
}

int	Form::getGradeExec() const
{
	return this->_gradeExec;
}

bool	Form::getSign(void) const
{
	return this->_sign;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade to hight !!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade to low !!");
}

const char *Form::FormNotSignedException::what() const throw()
{
	return ("The Form isn't sign");
}

int	Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_sign = true;
	return (1);
}

std::ostream	&operator<<(std::ostream& os, Form const &src)
{
	os << src.getName() << " form " << (src.getSign() ? "is sign" : "isn't sign")
	<< ". Grade to be sign: " << src.getGrade()
	<< ", grade to be execute: " << src.getGradeExec();
	return (os);
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (!this->_sign)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->_gradeExec)
		throw Form::GradeTooLowException();
	action(this->_target);
}

std::string	Form::getTarget(void) const
{
	return (this->_target);
}

void	Form::setName(std::string name)
{
	this->_name = name;
}

void	Form::setGradeSign(int grade)
{
	this->_gradeSign = grade;
}

void	Form::setGradeExec(int grade)
{
	this->_gradeExec = grade;
}

void	Form::setSign(bool grade)
{
	this->_sign = grade;
}
