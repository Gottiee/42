#include "../header/Convert.hpp"

Convert::Convert()
{
}

bool	Convert::is_pse(std::string type)
{

	_wtf = 0;
	if (type == "-inf")
	{
		this->_double = std::numeric_limits<double>::infinity();
		this->_double *= -1;
		_wtf = 1;
		convert_double(this->_double);
		return true;
	}
	if (type == "+inf")
	{
		this->_double = std::numeric_limits<double>::infinity();
		_wtf = 1;
		convert_double(this->_double);
		return true;
	}
	if (type == "nan")
	{
		this->_double = std::numeric_limits<double>::quiet_NaN();
		_wtf = 1;
		convert_double(this->_double);
		return true;
	}
	if (type == "-inff")
	{
		this->_float = std::numeric_limits<double>::infinity();
		this->_float *= -1;
		_wtf = 1;
		convert_float(this->_float);
		return true;
	}
	if (type == "+inff")
	{
		this->_float = std::numeric_limits<double>::infinity();
		convert_float(this->_float);
		_wtf = 1;
		return true;
	}
	if (type == "nanf")
	{
		this->_float = std::numeric_limits<double>::quiet_NaN();
		_wtf = 1;
		convert_float(this->_float);
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
	std::cout << "char: ";
	if (_int < 32 || _int > 126)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(_int) << "'" << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << static_cast<float>(_int) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(_int) << ".0" << std::endl;
}

void	Convert::convert_double(double _double)
{
	double tmp = _double - static_cast<int>(_double);

	std::cout << "char: ";
	if (_wtf)
		std::cout << "impossible\n";
	else if (_double < 32 || _double > 126)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(_double) << "'" << std::endl;
	if (_wtf)
		std::cout << "int: impossible\n";
	else 
		std::cout << "int: " << static_cast<int>(_double) << std::endl;
	std::cout << "float: " << static_cast<float>(_double);
	if (!tmp)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << _double;
	if (!tmp)
		std::cout << ".0";
	std::cout << std::endl;
}	

void	Convert::convert_char(char _char)
{
	std::cout << "char: "  << "'" << _char << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(_char) << std::endl;
	std::cout << "float: " << static_cast<float>(_char) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(_char) << ".0" << std::endl;
}

void	Convert::convert_float(float _float)
{
	float tmp = _float - static_cast<int>(_float);

	std::cout << "char: ";
	if (_wtf)
		std::cout << "impossible\n";
	else if (_float < 32 || _float > 126)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(_float) << "'" << std::endl;
	if (_wtf)
		std::cout << "int: impossible\n";
	else 
		std::cout << "int: " << static_cast<int>(_float) << std::endl;
	std::cout << "float: " << _float;
	if (!tmp)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << static_cast<float>(_float);
	if (!tmp)
		std::cout << ".0";
	std::cout << std::endl;
}
