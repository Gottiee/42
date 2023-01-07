#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

class sizePro: public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return ("The array is smaller than the unsigned int you enter");
	}
};

template < typename T >
class Array
{
	public:

	Array(): _size(0)
	{
		_tab = new T[0];
	}

	Array(unsigned int n): _size(n)
	{
		_tab = new T[n];
	}

	Array(const Array &src)
	{
		_tab = new T[src._size];
		_size = src._size;
		for (unsigned int i = 0; i < _size; i ++)
			_tab[i] = src._tab[i];
	}

	T &operator=(const Array &src)
	{
		delete [] _tab;
		_tab = new T[src._size];
		_size = src._size;
		for (int i = 0; i < _size; i ++)
			_tab[i] = src._tab[i];		
		return (*this);
	}

	T	&operator[](unsigned int i)
	{
		if (i >= _size)
			throw sizePro();
		return (_tab[i]);
	}

	unsigned int size() const
	{
		return(_size);
	}

	~Array()
	{
		delete [] _tab;
		_size = 0;
	}

	private:
	T 				*_tab;
	unsigned int	_size;
};

#endif
