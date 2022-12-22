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
	else
	{
		if (is_pse(type))
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

bool	Convert::is_pse(std::string type)
{
	if (type == "-inf")
	{
		this->_double = std::numeric_limits<double>::infinity();
		this->_double *= -1;
		return true;
	}
	if (type == "+inf")
	{
		this->_double = std::numeric_limits<double>::infinity();
		return true;
	}
	if (type == "nan")
	{
		this->_double = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	if (type == "-inff")
	{
		this->_float = std::numeric_limits<double>::infinity();
		this->_float *= -1;
		return true;
	}
	if (type == "+inff")
	{
		this->_float = std::numeric_limits<double>::infinity();
		std::cout << this->_float << std::endl;
		return true;
	}
	if (type == "nanf")
	{
		this->_float = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	return false;
}
