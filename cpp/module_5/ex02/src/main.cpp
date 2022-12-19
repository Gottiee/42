#include "../header/Bureaucrat.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "---Form isnt signed--" << std::endl << std::endl;
	try
	{
		Bureaucrat roger("roger", 15);
		PresidentialPardonForm pres("The goat");
		roger.executeForm(pres);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---Form is signed but grade to low--" << std::endl << std::endl;
	try
	{
		Bureaucrat roger("roger", 24);
		PresidentialPardonForm pres("The goat");
		roger.signForm(pres);
		roger.executeForm(pres);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---Form is signed and grade good--" << std::endl << std::endl;
	try
	{
		Bureaucrat roger("roger", 4);
		PresidentialPardonForm pres("The goat");
		roger.signForm(pres);
		roger.executeForm(pres);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---testing = operator--" << std::endl << std::endl;
	try
	{
		Bureaucrat roger("roger", 4);
		PresidentialPardonForm pres("The goat");
		PresidentialPardonForm cp("ma");
		cp = pres;
		roger.signForm(pres);
		roger.executeForm(pres);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "---Test for Robot--" << std::endl << std::endl;
	try
	{
		Bureaucrat roger("roger", 4);
		RobotomyRequestForm pres("The bunny");
		roger.signForm(pres);
		roger.executeForm(pres);
		roger.executeForm(pres);
		roger.executeForm(pres);
		roger.executeForm(pres);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}
}
