#include "../header/Bureaucrat.hpp"

int main(void)
{
	std::cout << "---Grade too low--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 171);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "---Grade too hight--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "---Good and decrement to low grade--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 149);
		std::cout << bob << std::endl;
		bob--;
		std::cout << bob << std::endl;
		bob--;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
   		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "---Good and increment to hight grade--" << std::endl << std::endl;
	try
	{
		Bureaucrat	bob("bob", 2);
		std::cout << bob << std::endl;
		bob++;
		std::cout << bob << std::endl;
		bob++;
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
