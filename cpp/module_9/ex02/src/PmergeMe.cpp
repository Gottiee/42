#include "../header/PmergeMe.hpp"

int	PmergeMe::K = 5;

PmergeMe::PmergeMe(std::vector<unsigned int> numbers, u_de deque):_numb(numbers), _que(deque)
{
	try
	{
		print_vec("Before:");
		result = clock();
		sort(0, _numb.size() - 1);
		_time_vec = (float)(clock() - result) / CLOCKS_PER_SEC;
		result = clock();
		sort_de(0, _que.size() - 1);
		_time_other = (float)(clock() - result) / CLOCKS_PER_SEC;
		print_vec("After: ");
		print_time();
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
	_numb = src._numb;
	_que = src._que;
	_time_vec = src._time_vec;
	_time_other = src._time_other;
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

void	PmergeMe::insert_sort(int low, int high)
{
	unsigned int	key;
	int 			k;
	for (int i = low; i < high; i ++)	
	{
		key = _numb[i + 1];
		k = i + 1;
		while (k > low && _numb[k - 1] > key)
		{
			_numb[k] = _numb[k - 1];
			k--;
		}
		_numb[k] = key;
	}
}

void	PmergeMe::sort(int low, int high)
{
	if (high - low > K)
	{
		int mid = (low + high) / 2;
		sort(low, mid);
		sort(mid + 1, high);
		merge(low, high, mid);
    }
	else
		insert_sort(low, high);
}

void	PmergeMe::merge(int low, int high, int mid)
{
	int 	n1 = mid - low + 1;
	int 	n2 = high - mid;
	u_vec	LA(_numb.begin() + low, _numb.begin() + mid + 1);
	u_vec	MA(_numb.begin() + mid + 1, _numb.begin() + high + 1);
	int 	i, j, k;

	i = 0;
	j = 0;
	k = low;
	while (i < n1 && j < n2)
	{
		if (LA[i] <= MA[j])
		{
			_numb[k] = LA[i];
			i ++;
		}
		else
		{
			_numb[k] = MA[j];
			j ++;
		}
		k ++;
	}
	while (i < n1)
	{
		_numb[k] = LA[i];
		i ++;
		k ++;
	}
	while (j < n2)
	{
		_numb[k] = MA[j];
		j ++;
		k ++;
	}
}

void PmergeMe::print_vec(std::string str)
{
	std::cout << str;
	for (u_vec::iterator it = _numb.begin(); it != _numb.end(); it ++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::print_time()
{
	std::cout << std::fixed;
	std::cout << "Time to process a range of " << _numb.size() << " elements with std::vector : " << std::setprecision(5) << _time_vec << " seconds\n";
	std::cout << "Time to process a range of " << _numb.size() << " elements with std::deque : " << std::setprecision(5) << _time_other << " seconds\n";
}

void	PmergeMe::insert_sort_de(int low, int high)
{
	unsigned int	key;
	int 			k;
	for (int i = low; i < high; i ++)	
	{
		key = _que[i + 1];
		k = i + 1;
		while (k > low && _que[k - 1] > key)
		{
			_que[k] = _que[k - 1];
			k--;
		}
		_que[k] = key;
	}
}

void	PmergeMe::sort_de(int low, int high)
{
	if (high - low > K)
	{
		int mid = (low + high) / 2;
		sort_de(low, mid);
		sort_de(mid + 1, high);
		merge_de(low, high, mid);
    }
	else
		insert_sort_de(low, high);
}

void	PmergeMe::merge_de(int low, int high, int mid)
{
	int 	n1 = mid - low + 1;
	int 	n2 = high - mid;
	u_vec	LA(_que.begin() + low, _que.begin() + mid + 1);
	u_vec	MA(_que.begin() + mid + 1, _que.begin() + high + 1);
	int 	i, j, k;

	i = 0;
	j = 0;
	k = low;
	while (i < n1 && j < n2)
	{
		if (LA[i] <= MA[j])
		{
			_que[k] = LA[i];
			i ++;
		}
		else
		{
			_que[k] = MA[j];
			j ++;
		}
		k ++;
	}
	while (i < n1)
	{
		_que[k] = LA[i];
		i ++;
		k ++;
	}
	while (j < n2)
	{
		_que[k] = MA[j];
		j ++;
		k ++;
	}
}
