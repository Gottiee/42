#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Span
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Span(unsigned int);
	Span(Span const &src);
	~Span();
	Span	&operator=(Span const &src);
	void	addNumber(int n);
	class	TooMuchNumb: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class	ShortFuncError: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class	LongFuncError: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	int		shortestSpan() const;
	int		longestSpan() const;
	void	addNumberRang();

	private:
	unsigned int		_n;
	std::vector<int>	_vec;
	unsigned int		_n_of_num;
	Span();

};

int	rando(unsigned int nb);

#endif
