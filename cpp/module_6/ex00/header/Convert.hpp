#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>

class Convert
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Convert(std::string);
	Convert(Convert const &src);
	~Convert();
	Convert	&operator=(Convert const &src);
	void	shine(void);

	private:
	Convert();
	int		_int;
	double	_double;
	float	_float;
	char	_char;

};

#endif
