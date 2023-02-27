#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <string>
#include <vector>
#include <cstdlib>

typedef std::vector<unsigned int> u_vec;

class PmergeMe
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	PmergeMe(std::vector<unsigned int>);
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe	&operator=(PmergeMe const &src);
	void		sort(u_vec, int p, int r);
	void		merge(u_vec, int p, int q, int r);

	private:
	PmergeMe();
	u_vec	_numb;
};

unsigned int	pars_numb(std::string num);

#endif
