#include "../header/Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int n): _n(n)
{
	
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
	return *this;
}
