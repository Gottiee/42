#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed	&operator=(Fixed const &src);
	private:
	int					_n;
	static const int	_bits;
};

#endif
