#include "../Fixed.hpp"

int Fixed::_bits = 8;

Fixed::Fixed(): _n(0)
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(int const n)
{
	this->_n = n << this->_bits;
}

Fixed::Fixed(float const n)
{
	this->_n = (int)roundf(n * (1 << this->_bits));
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	this->_n = src.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return o;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_n / (1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return (this->_n >> this->_bits);
}

Fixed	&Fixed::operator++(void)
{
	this->_n ++;
	return *this; 
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_n ++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_n --;
	return *this; 
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_n --;
	return (tmp);
}

const Fixed	&Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 < ref2)	
		return ref1;
	return ref2;
}

Fixed	&Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 < ref2)	
		return ref1;
	return ref2;
}

const Fixed	&Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)	
		return ref1;
	return ref2;
}

Fixed	&Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)	
		return ref1;
	return ref2;
}

/*return 1 si srcA et plus grande que srcB*/
int	operator>(Fixed const &srcA, Fixed const &srcB)
{
	if (srcA.getRawBits() > srcB.getRawBits())	
		return (1);
	return (0);
}

int	operator<(Fixed const &srcA, Fixed const &srcB)
{
	if (srcA.getRawBits() < srcB.getRawBits())	
		return (1);
	return (0);
}

int	operator<=(Fixed const &srcA, Fixed const &srcB)
{
	if (srcA.getRawBits() <= srcB.getRawBits())	
		return (1);
	return (0);
}

int	operator>=(Fixed const &srcA, Fixed const &srcB)
{
	if (srcA.getRawBits() >= srcB.getRawBits())	
		return (1);
	return (0);
}

int	operator==(Fixed const &srcA, Fixed const &srcB)
{
	if (srcA.getRawBits() == srcB.getRawBits())	
		return (1);
	return (0);
}

int	operator!=(Fixed const &srcA, Fixed const &srcB)
{
	if (srcA.getRawBits() != srcB.getRawBits())	
		return (1);
	return (0);
}

Fixed	operator+(Fixed const &srcA, Fixed const &srcB)
{
	return Fixed(srcA.toFloat() + srcB.toFloat());
}

Fixed	operator-(Fixed const &srcA, Fixed const &srcB)
{
	return Fixed(srcA.toFloat() - srcB.toFloat());
}

Fixed	operator*(Fixed const &srcA, Fixed const &srcB)
{
	return Fixed(srcA.toFloat() * srcB.toFloat());
}

Fixed	operator/(Fixed const &srcA, Fixed const &srcB)
{
	return Fixed(srcA.toFloat() / srcB.toFloat());
}
