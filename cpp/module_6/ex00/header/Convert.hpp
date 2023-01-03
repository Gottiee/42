#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

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
	void	convert_int(int);
	void	convert_char(char);
	void	convert_double(double);
	void	convert_float(float);
	bool	is_pse(std::string);
	bool	is_int(std::string);
	bool	is_double(std::string);
	bool	is_float(std::string);

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

	class IntPro: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class DoublePro: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};
	class FloatPro: public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	private:
	Convert();
	int			_int;
	double		_double;
	float		_float;
	char		_char;
};

#endif
