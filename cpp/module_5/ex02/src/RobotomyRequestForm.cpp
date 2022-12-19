#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Default constructor call for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "Target constructor call for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
	*this = src;
	std::cout << "Copy constructor call for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default destuctor call for RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	std::cout << "Default assignement constructor call for RobotomyRequestForm" << std::endl;
	this->_target = src.getTarget();
	setName(src.getName());
	setGradeSign(src.getGrade());
	setGradeExec(src.getGradeExec());
	setSign(src.getSign());
	return *this;
}

void	RobotomyRequestForm::action(std::string target) const
{
	std::cout << "Bzzzz... PSHIIIIII... BzBZZ... ";
	if (randomBool())
		std::cout << target << " has been robotized" << std::endl;
	else
		std::cout << target << "'s operation has been failed" << std::endl;

}

bool	RobotomyRequestForm::randomBool(void) const
{
	int a;

	a = rand() ;
	std::cout << "a =" << a << std::endl;
	return a;
}
