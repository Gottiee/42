#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <list>

template < typename T >
class MutantStack: public std::stack<T>
{
	public:
	MutantStack(){}
	MutantStack(MutantStack &src)
	{
		*this = src;
	}
	MutantStack &operator=(const MutantStack &src)
	{
		this = &src	;
		return *this;
	}
	~MutantStack(){}

	typedef typename std::deque<T>::iterator iterator;
	iterator begin(void)
	{
		return (this->c.begin());
	}
	iterator end(void)
	{
		return (this->c.end());
	}
};
#endif
