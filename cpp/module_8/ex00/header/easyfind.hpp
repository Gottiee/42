#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <exception>
#include <algorithm>

template < typename T >
typename T::iterator easyfind(T & container, int looking_for)
{
	try
	{
		typename T::iterator	it;
		it = std::find(container.begin(), container.end(), looking_for);
		if (it == container.end())
			throw std::exception();
		return it;
	}
	catch (std::exception &e)
	{
		std::cerr << "No occurance of: " << looking_for << " in the container\n";
	}
	return container.begin(); 
}


#endif
