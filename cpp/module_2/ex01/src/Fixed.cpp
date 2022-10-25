#include "../Fixed.hpp"

int Fixed::_bits = 8;

Fixed::Fixed(): _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = n << this->_bits;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
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
