#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <time.h>

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
	void		sort(int, int);
	void		print_vec(std::string);
	void		merge(int, int, int);
	void		insert_sort(int, int);
	void		print_time();
	static int	K;

	private:
	PmergeMe();
	u_vec		_numb;
	float		_time_other;
	clock_t		result;
};

unsigned int	pars_numb(std::string num);

#endif
