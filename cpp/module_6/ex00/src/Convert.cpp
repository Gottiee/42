#include "../header/Convert.hpp"

Convert::Convert()
{
}

bool	Convert::is_pse(std::string type)
{
	if (type == "-inf")
	{
		this->_double = std::numeric_limits<double>::infinity();
		this->_double *= -1;
		convert_double(this->_double);
		return true;
	}
	if (type == "+inf")
	{
		this->_double = std::numeric_limits<double>::infinity();
		convert_double(this->_double);
		return true;
	}
	if (type == "nan")
	{
		this->_double = std::numeric_limits<double>::quiet_NaN();
		convert_double(this->_double);
		return true;
	}
	if (type == "-inff")
	{
		this->_float = std::numeric_limits<double>::infinity();
		this->_float *= -1;
		convert_double(this->_double);
		return true;
	}
	if (type == "+inff")
	{
		this->_float = std::numeric_limits<double>::infinity();
		convert_double(this->_double);
		return true;
	}
	if (type == "nanf")
	{
		this->_float = std::numeric_limits<double>::quiet_NaN();
		convert_double(this->_double);
		return true;
	}
	return false;
}

bool	Convert::is_int(std::string type)
{
	if (type.find(".") != std::string::npos || type.find("f") != std::string::npos)
		return (false);
	if (std::atol(type.c_str()) > INT_MAX || std::atol(type.c_str()) < INT_MIN)
	{
		throw Convert::IntPro();
		return (false);
	}
	for (int i = 0; type[i]; i ++)
	{
		if ((type[i] == '-' || type[i] == '+') && i == 0)
			i ++;
		if (!isdigit(type[i]))
		{
			throw Convert::IntPro();
			return (false);
		}
	}
	this->_int = std::atoi(type.c_str());
	Convert::convert_int(this->_int);
	return (true);
}

bool	Convert::is_double(std::string type)
{
	int bolo = 0;
	
	if (type.find(".") == std::string::npos || type.find("f") != std::string::npos)
		return (false);
	for (int i = 0; type[i]; i ++)
	{
		if ((type[i] == '-' || type[i] == '+') && i == 0)
			i ++;
		if (type[i] == '.' && bolo == 0)
		{
			i ++;
			bolo ++;
		}
		if (!isdigit(type[i]))
		{
			throw Convert::DoublePro();
			return (false);
		}
	}
	this->_double = std::atof(type.c_str());
	Convert::convert_double(this->_double);
	return (true);
}

bool	Convert::is_float(std::string type)
{
	int bolo = 0;

	if (type.find(".") == std::string::npos || type.find("f") == std::string::npos)
		return (false);
	for (int i = 0; type[i]; i ++)
	{
		if ((type[i] == '-' || type[i] == '+') && i == 0)
			i ++;
		if (type[i] == '.' && bolo == 0)
		{
			i ++;
			bolo ++;
		}
		if (!isdigit(type[i]) && (type[i] == 'f' && type[i + 1]))
		{
			throw Convert::FloatPro();
			return (false);
		}
	}
	this->_float = std::atof(type.c_str());
	Convert::convert_float(this->_float);
	return (true);
}

Convert::Convert(std::string type)
{
	try
	{
		if (type.empty())	
			throw Convert::Empty();
		if (type.size() == 1)
		{
			if (std::isdigit(type[0]))
			{
				this->_int = std::atoi(type.c_str());
				Convert::convert_int(this->_int);
			}
			else if (type[0] >= 32 && type[0] < 127)
			{
				this->_char = type[0];
				Convert::convert_char(this->_char);
			}
			else 
				throw Convert::NoneChar();
			return ;
		}
		else if (is_pse(type))
			return ;
		else if (is_int(type))
			return ;
		else if (is_double(type))
			return ;
		else if (is_float(type))
			return ;
	}
	catch (Convert::IntPro &e)
	{
		throw;	
	}
	catch (Convert::DoublePro &e)
	{
		throw;
	}
	catch (Convert::FloatPro &e)
	{
		throw;
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

const char *Convert::IntPro::what() const throw()
{
	return ("Int problem");
}

const char *Convert::DoublePro::what() const throw()
{
	return ("Double problem");
}

const char *Convert::FloatPro::what() const throw()
{
	return ("Float problem");
}

void	Convert::convert_int(int _int)
{
	if (_int < 32 || _int > 126)

	std::cout << "int = " << _int << std::endl;
}

void	Convert::convert_double(double _double)
{
	std::cout << "double = " << _double << std::endl;
}

void	Convert::convert_char(char _char)
{
	std::cout << "char = " << _char << std::endl;
}

void	Convert::convert_float(float _float)
{
	std::cout << "float = " << _float << std::endl;
}