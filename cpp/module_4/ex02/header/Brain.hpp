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
	Brain		&operator=(Brain const &src);
	void		setIdeas(std::string idea);
	void		printIdea(void);
	std::string	*getStringBrain();
	void		setFullIdeas(std::string idea[100]);
	std::string	getString(int i) const;

	private:
	std::string ideas[100];

};

#endif
