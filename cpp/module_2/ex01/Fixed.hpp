#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(int const n);
	Fixed(float const n);
	~Fixed();
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;
	Fixed			&operator=(Fixed const &src);

	private:
	int			_n;
	static int	_bits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);
#endif
