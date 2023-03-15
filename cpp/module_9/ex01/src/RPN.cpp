#include "../header/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN	&RPN::operator=(RPN const &src)
{
	stack = src.stack;
	return *this;
}

RPN::RPN(std::string str)
{
	try
	{
		calcul(str);
	}
	catch (std::exception &e)
	{
		throw;
	}
}

void RPN::calcul(std::string str)
{
	int i = 0;
	int a;
	int b;
	int opera;
	
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			stack.push(str[i] - 48);
			i ++;
			if (str[i] && str[i] != ' ')
			{
				std::cerr << "Error: number range 0-9\n";
				throw std::exception();
			}
			if (str[i])
				i ++;
		}
		else 
		{
			opera = operation(str[i]);
			if (!opera)
			{
				std::cerr << "Error: bad operator\n";
				throw std::exception();
			}
			if (stack.size() < 2)
			{
				std::cerr << "Error: missing operand\n";
				throw std::exception();
			}
			a = stack.top();	
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(do_operator(opera, a, b));
			i ++;
			if (str[i] && str[i] != ' ')
			{
				std::cerr << "Error: cant accept none separate operator\n";
				throw std::exception();
			}
			if (str[i])
				i ++;
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error: missing operator\n";
		throw std::exception();
	}
	std::cout << stack.top() << std::endl;
}

int	RPN::do_operator(int opera, int a, int b)
{
	if (opera == plus)	
		return b + a;
	if (opera == min)
		return b - a;
	if (opera == div)
		return b / a;
	if (opera == mult)
		return b * a;
	return 0;
}

int	RPN::operation(char c)
{
	if (c == '+')
		return plus;
	if (c == '-')
		return min;
	if (c == '*')
		return mult;
	if (c == '/')
		return div;
	return 0;
}
