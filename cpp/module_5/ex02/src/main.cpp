#include "../header/Bureaucrat.hpp"
#include "../header/PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		PresidentialPardonForm pres("ok");
		std::cout << pres << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}
/*std::cout << "---Form Grade too low--" << std::endl << std::endl;
	try
	{
		Form	bob("33A", 171, 15);
	}
	catch (Form::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "---Form Grade too hight--" << std::endl << std::endl;
	try
	{
		Form	bob("33A", 0, 15);
	}
	catch (Form::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "---Good and be signed--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 100);
		Form		form("33A", 111, 1);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "---Good but can't be signed--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 100);
		Form		form("33A", 10, 1);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "---Good but already signed--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 100);
		Bureaucrat	harry("harry", 100);
		Form		form("33A", 111, 1);
		std::cout << bob << std::endl;
		std::cout << form << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		harry.signForm(form);
		std::cout << form << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}*/	
}
