#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	Brain();
	Brain(Brain const &src);
	~Brain();
	Brain	&operator=(Brain const &src);

	private:
	std::string ideas[100];

};

#endif
