#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Default constructor call for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "Default constructor call for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
	*this = src;
	std::cout << "Copy constructor call for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default destuctor call for ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "Default assignement constructor call for ShrubberyCreationForm" << std::endl;
	this->_target = src.getTarget();
	setName(src.getName());
	setGradeSign(src.getGrade());
	setGradeExec(src.getGradeExec());
	setSign(src.getSign());
	return *this;
}

void	ShrubberyCreationForm::action(std::string target) const
{
	std::ofstream ofs;	
	
	target += "_shrubbery";
	ofs.open(target.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail())
	{
		std::perror("error");
		return ;
	}
	int width = 5, height = 11 , i, j, k, n = 1;
	int space = width * height;
	ofs << "Printing Christmas Tree Pattern of Stars\n";
	for (int x = 1; x <= height; x++)
	{
		for (i = n; i <= width; i++)
		{
			for (j = space; j >= i; j--)
			{
				ofs <<" ";
			}
			for (k = 1; k <= i; k++)
			{
				ofs <<"* ";
			}
			ofs <<"\n";
		}
		n = n + 2;
		width = width + 2;
	}
	for (i = 1; i <= height - 1; i++)
	{
		for (j = space - 3 - 5; j >= 0; j--)
		{
			ofs << " ";
		}
		for (k = 1; k <= height - 1; k++)
		{
			ofs << "* ";
		}
		ofs << "\n";
	}
	ofs.close();
}
