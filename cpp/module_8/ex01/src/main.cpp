#include "../header/Span.hpp"
#include <climits>
#include <ctime>

int	rando(void)
{
	int res;
	res =rand() % 10000;
	std::cout << res << std::endl;
	return res;
}

int main(void)
{
	std::srand(time(0));

	Span	span(10);
	Span	test(10);

	std::cout << "---Short Vector Test---\n\n";
	
	span.addNumberRang();
	std::cout << "span.shortestSpan()= " << span.shortestSpan() << std::endl;
	std::cout << "span.longestSpan()= " << span.longestSpan() << std::endl;

	std::cout << "\n---Short Vector Test---\n\n";
	test.addNumberRang();
}
