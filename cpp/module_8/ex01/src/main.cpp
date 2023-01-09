#include "../header/Span.hpp"
#include <climits>
#include <ctime>

int	rando(unsigned int nb)
{
	int	res;
	if (nb == 0)
		nb = rando(nb + 1);
	std::srand(std::time(NULL));
	for (unsigned int i = 0; i < nb; i++)
		res = rand() % (nb * 10);
	std::cout << res << std::endl;
	return res;
}

int main(void)
{
	Span	span(10);
	int		numb;

	std::cout << "---Short Vector Test---\n\n";
	
	for (int i = 0; i < 10; i ++)
	{
		numb = rando(i);
		span.addNumber(numb);
	}
	std::cout << "span.shortestSpan()= " << span.shortestSpan() << std::endl;
	std::cout << "span.longestSpan()= " << span.longestSpan() << std::endl;

	std::cout << "\n---Short Vector Test---\n\n";
	span.addNumberRang();
}
