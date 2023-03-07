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
#include <deque>

typedef std::vector<unsigned int> u_vec;
typedef std::deque<unsigned int> u_de;


class PmergeMe
{

	/*******************/
	/*      CANON      */
	/*******************/

	public:
	PmergeMe(std::vector<unsigned int>, u_de);
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe	&operator=(PmergeMe const &src);
	void		sort(int, int);
	void		sort_de(int, int);
	void		print_vec(std::string);
	void		merge(int, int, int);
	void		merge_de(int, int, int);
	void		insert_sort(int, int);
	void		insert_sort_de(int, int);
	void		print_time();
	static int	K;

	private:
	PmergeMe();
	u_vec		_numb;
	u_de		_que;
	float		_time_vec;
	float		_time_other;
	clock_t		result;
};

unsigned int	pars_numb(std::string num);

#endif
