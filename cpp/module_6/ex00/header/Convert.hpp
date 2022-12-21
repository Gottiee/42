#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

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

	class Empty: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class NoneChar: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	private:
	Convert();
	std::string _type;
	int			_int;
	double		_double;
	float		_float;
	char		_char;
};

#endif
