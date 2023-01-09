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


	private:
	unsigned int _n;
	std::vector
	Span();

};

#endif
