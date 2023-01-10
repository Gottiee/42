#include "../header/Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n): _n(n), _n_of_num(0)
{
	_vec.resize(n);
}

const char *Span::TooMuchNumb::what() const throw()
{
	return ("Too Much number in class Span");
}

const char *Span::ShortFuncError::what() const throw()
{
	return ("Error occurcing while using short function\n");
}

const char *Span::LongFuncError::what() const throw()
{
	return ("Error occurcing while using long function\n");
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &src)
{
	(void)src;
	return *this;
}

void	Span::addNumber(int n)
{
	if (_n_of_num < _n)
		_vec[_n_of_num] = n;
	else
		throw Span::TooMuchNumb();
	_n_of_num ++;
}

int	Span::shortestSpan() const
{
	std::vector<int>::const_iterator	it;

	if (_n_of_num != 0 || _n != 1)	
	{
		it = min_element(_vec.begin(), _vec.end());
		if (it != _vec.end())
			return (static_cast<int>(*it));
	}
	throw Span::ShortFuncError();
	return 0;
}

int	Span::longestSpan() const
{
	std::vector<int>::const_iterator	it;

	if (_n_of_num != 0 || _n != 1)	
	{
		it = max_element(_vec.begin(), _vec.end());
		if (it != _vec.end())
			return (static_cast<int>(*it));
	}
	throw Span::LongFuncError();
	return 0;

}

void	Span::addNumberRang()
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	ite = _vec.end();

	for (it = _vec.begin(); it != ite; it++)
	{
		*it = rando();
	}
}
