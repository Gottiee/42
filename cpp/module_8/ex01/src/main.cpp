#include "../header/Span.hpp"
#include <climits>
#include <ctime>

int	rando(void)
{
	int res;
	res =rand() % 1000000;
	std::cout << res << std::endl;
	return res;
}

int main(void)
{
	std::srand(time(0));
	Span span(5);
	Span sp_negative(3);
	Span sp_little(1);
	Span sp_big(10);
	Span sp_verybig(10000);

	std::cout << "---- Standard test ----" << std::endl;
	try
	{	
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest: " << span.longestSpan() << std::endl << std::endl;
	}
	catch(Span::TooMuchNumb &e)
	{
		std::cerr << e.what();
	}
	catch(Span::ShortFuncError &e)
	{
		std::cerr << e.what();
	}
	catch(Span::LongFuncError &e)
	{
		std::cerr << e.what();
	}
	std::cout << "---- Test with negatives values ----" << std::endl;
	try
	{
		sp_negative.addNumber(-45);
		sp_negative.addNumber(-1);
		sp_negative.addNumber(-4);

		std::cout << "Shortest: " << sp_negative.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp_negative.longestSpan() << std::endl << std::endl;
	}
	catch(Span::TooMuchNumb &e)
	{
		std::cerr << e.what();
	}
	catch(Span::ShortFuncError &e)
	{
		std::cerr << e.what();
	}
	catch(Span::LongFuncError &e)
	{
		std::cerr << e.what();
	}
	std::cout << "---- Test with not enough values ----" << std::endl;
	try
	{
		sp_little.addNumber(42);

		std::cout << "Shortest: " << sp_little.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp_little.longestSpan() << std::endl << std::endl;
	}
	catch(Span::TooMuchNumb &e)
	{
		std::cerr << e.what();
	}
	catch(Span::ShortFuncError &e)
	{
		std::cerr << e.what();
	}
	catch(Span::LongFuncError &e)
	{
		std::cerr << e.what();
	}
	std::cout << "---- Test with too much values added ----" << std::endl;
	try
	{
		sp_big.addNumberRang();
		sp_big.addNumber(42);
	}
	catch(Span::TooMuchNumb &e)
	{
		std::cerr << e.what();
	}
	catch(Span::ShortFuncError &e)
	{
		std::cerr << e.what();
	}
	catch(Span::LongFuncError &e)
	{
		std::cerr << e.what();
	}
std::cout << "---- Test with 10 000 values ----" << std::endl;
	try
	{
		sp_verybig.addNumberRang();
		std::cout << "Shortest: " << sp_verybig.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp_verybig.longestSpan() << std::endl;
	}
	catch(Span::TooMuchNumb &e)
	{
		std::cerr << e.what();
	}
	catch(Span::ShortFuncError &e)
	{
		std::cerr << e.what();
	}
	catch(Span::LongFuncError &e)
	{
		std::cerr << e.what();
	}	
}
