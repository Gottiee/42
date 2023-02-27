#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<unsigned int> numbers):_numb(numbers)
{
	try
	{
		sort(_numb, 0, _numb.size() - 1);
	}
	catch (std::exception &e)
	{
	
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	//remplir ici
	_numb = src._numb;
	return *this;
}

unsigned int	pars_numb(std::string num)
{
	unsigned long	lng;

	for (int i = 0; num[i]; i ++)	
	{
		if(!std::isdigit(num[i]))
		{
			std::cerr << "arguments only require numbers\n";
			throw std::exception();
		}
	}
	lng	= std::atol(num.c_str());
	if (lng > 4294967295 || num.size() > 10)
	{
		std::cerr << "Arguments rang to wild\n";
		throw std::exception();
	}
	return (unsigned int)lng;
}


void	PmergeMe::sort(u_vec vec, int p, int r)
{
	if (p > r)
		return;
	int q = (p + r / 2);
	sort(vec, p, q);
	sort(vec, q + 1, r);
	merge(vec, p, q, r);
}

void	PmergeMe::merge(u_vec vec, int p, int q, int r)
{
	u_vec L(vec.begin() + p, vec.begin() + q);
	u_vec M(vec.begin() + q + 1, vec.begin() + r);
	for (u_vec::iterator it = L.begin(); it != L.end(); it ++)
		std::cout << "L =" << *it << std::endl;
	for (u_vec::iterator it = M.begin(); it != M.end(); it ++)
		std::cout << "M =" << *it << std::endl;
}
