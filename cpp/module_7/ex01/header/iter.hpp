#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename C>
void	print(C const c)
{
	std::cout << c << std::endl;
}

template< typename Add, typename Size, typename Function >
void	iter(Add *add, Size size, Function function)
{
	for (int i = 0; i < size; i++)	
	{
		function(add[i]);
	}
}

#endif
