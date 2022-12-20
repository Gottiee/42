#include "../header/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return *this;
}

Form	*Intern::makeForm(std::string const &name, std::string const &target)
{
	Form	*result = NULL;

	t_form	data[] = 
	{
		{ "PresidentialPardonForm", new PresidentialPardonForm(target) },
		{ "RobotomyRequestForm", new RobotomyRequestForm(target) },
		{ "ShrubberyCreationForm", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};

	for (int i = 0; i < 4; i ++)
	{
		if (data[i].target == name)
			result = data[i].form;
		else
			delete(data[i].form);
	}
	if (!result)
	{
		std::cerr << "Form: " << name << " doesn't exist." << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << name << std::endl;
	return (result);
}
