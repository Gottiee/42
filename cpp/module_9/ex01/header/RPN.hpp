#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stack>

#define plus 1
#define min 2
#define mult 3 
#define div 4

class RPN
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	RPN(std::string);
	RPN(RPN const &src);
	~RPN();
	RPN	&operator=(RPN const &src);
	void	calcul(std::string);
	int	operation(char);
	int	do_operator(int opera, int a, int b);

	private:
	RPN();
	std::stack<int>	stack;

};

#endif
