#include "../header/Convert.hpp"

Convert::Convert()
{
}

Convert::Convert(std::string type)
{
	if (type.empty())	
		throw Convert::Empty();
	if (type.size() == 1)
	{
		if (std::isdigit(type[0]))
		{
			this->_int = std::atoi(type.c_str());
			this->_type = "int";
		}
		else if (type[0] >= 32 && type[0] < 127)
		{
			this->_char = type[0];
			this->_type = "char";
		}
		else 
			throw Convert::NoneChar();
		return ;
	}
}

Convert::Convert(Convert const &src)
{
	*this = src;
}

Convert::~Convert()
{
}

Convert	&Convert::operator=(Convert const &src)
{
	(void)src;
	return *this;
}

const char *Convert::Empty::what() const throw()
{
	return ("The string is empty");
}

const char *Convert::NoneChar::what() const throw()
{
	return ("This char isn't printable");
}
