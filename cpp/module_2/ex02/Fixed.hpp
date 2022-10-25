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
	Fixed			&operator++(void);
	Fixed			operator++(int);
	Fixed			&operator--(void);
	Fixed			operator--(int);
	static int		min(int const &ref1, int const &ref2);
	static int		min(int &ref1, int &ref2);
	static int		max(int const &ref1, int const &ref2);
	static int		max(int &ref1, int &ref2);

	private:
	int			_n;
	static int	_bits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &src);
int				operator>(Fixed const &srcA, Fixed const &srcB);
int				operator<(Fixed const &srcA, Fixed const &srcB);
int				operator<=(Fixed const &srcA, Fixed const &srcB);
int				operator>=(Fixed const &srcA, Fixed const &srcB);
int				operator==(Fixed const &srcA, Fixed const &srcB);
int				operator!=(Fixed const &srcA, Fixed const &srcB);
Fixed			operator+(Fixed const &srcA, Fixed const &srcB);
Fixed			operator-(Fixed const &srcA, Fixed const &srcB);
Fixed			operator*(Fixed const &srcA, Fixed const &srcB);
Fixed			operator/(Fixed const &srcA, Fixed const &srcB);

#endif
