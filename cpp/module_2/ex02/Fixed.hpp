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
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	Fixed				&operator=(Fixed const &src);
	Fixed				&operator++(void);
	Fixed				operator++(int);
	Fixed				&operator--(void);
	Fixed				operator--(int);
	static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);
	static Fixed		&min(Fixed &ref1, Fixed &ref2);
	static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
	static Fixed		&max(Fixed &ref1, Fixed &ref2);

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
