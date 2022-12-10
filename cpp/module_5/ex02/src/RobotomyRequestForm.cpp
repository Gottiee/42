#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Default constructor call for RobotomyRequestForm" << std::endl;
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
	return *this;

}