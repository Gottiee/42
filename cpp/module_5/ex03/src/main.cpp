#include "../header/Bureaucrat.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/Intern.hpp"

int main(void)
{
	{
		std::cout << "---Wrong Form--" << std::endl << std::endl;
		Intern	stagiaire;
		Form	*form;

		form = stagiaire.makeForm("Wrong_one", "crevette");
		std::cout << form << std::endl;
	}
	{
		std::cout << std::endl << "---good Form--" << std::endl << std::endl;
		Intern		stagiaire;
		Form		*form;
		Bureaucrat	roger("roger", 4);

		form = stagiaire.makeForm("PresidentialPardonForm", "crevette");
		roger.signForm(*form);
		roger.executeForm(*form);
		delete form;
	}
}
