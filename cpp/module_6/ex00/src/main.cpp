#include "../header/Convert.hpp"

int main(int argc, char **argv)
{
	int count = 0;
	
	while (count < 19)
	{
		try
		{
			if (argc > 2 || argc == 1)
			{
				if (count == 0)
				{
					std::cout << "---Basic test---\n\n"
					<< "Char\n\n";
					std::cout << "\"d\" input\n";
					Convert d("d");
					count ++;
				}
				if (count == 1)
				{
					std::cout << "\n\"é\" input\n";
					count ++;
					Convert e("é");
				}
				if (count == 2)
				{
					std::cout << "\n\"dsjdk\" input\n";
					count ++;
					Convert ds("dsjdk");
				}
				if (count == 3)
				{
					std::cout << "\nInt\n\n";
					std::cout << "\"-10\" input\n";
					count ++;
					Convert ok("-10");
				}
				if (count == 4)
				{
					std::cout << "\n\"+103\" input\n";
					count ++;
					Convert plus("+103");
				}
				if (count == 5)
				{
					std::cout << "\n\"2147483647\" input\n";
					count ++;
					Convert max("2147483647");
				}
				if (count == 6)
				{
					std::cout << "\n\"2147483648\" input\n";
					count ++;
					Convert over("2147483648");
				}
				if (count == 7)
				{
					std::cout << "\nFloat\n\n";
					std::cout << "\"-10.0f\" input\n";
					count ++;
					Convert ok("-10.0f");
				}
				if (count == 8)
				{
					std::cout << "\n\"+103.3f\" input\n";
					count ++;
					Convert plus("+103.3f");
				}
				if (count == 9)
				{
					std::cout << "\n\"-45.4568f\" input\n";
					count ++;
					Convert max("-45.4568f");
				}
				if (count == 10)
				{
					std::cout << "\n\"+inff\" input\n";
					count ++;
					Convert over("+inff");
				}
				if (count == 11)
				{
					std::cout << "\n\"-inff\" input\n";
					count ++;
					Convert over("-inff");
				}
				if (count == 12)
				{
					std::cout << "\n\"nanf\" input\n";
					count ++;
					Convert over("nanf");
				}
				if (count == 13)
				{
					std::cout << "\nDouble\n\n";
					std::cout << "\"-10.0\" input\n";
					count ++;
					Convert ok("-10.0");
				}
				if (count == 14)
				{
					std::cout << "\n\"+103.3\" input\n";
					count ++;
					Convert plus("+103.3");
				}
				if (count == 15)
				{
					std::cout << "\n\"-45.4568f\" input\n";
					count ++;
					Convert max("-45.4568");
				}
				if (count == 16)
				{
					std::cout << "\n\"+inf\" input\n";
					count ++;
					Convert over("+inf");
				}
				if (count == 17)
				{
					std::cout << "\n\"-inf\" input\n";
					count ++;
					Convert over("-inf");
				}
				if (count == 18)
				{
					std::cout << "\n\"nan\" input\n";
					count ++;
					Convert over("nan");
				}
			}
			else
			{
				Convert	convert(argv[1]);
				count = 19;
			}
		}
		catch (Convert::Empty &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Convert::NoneChar &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Convert::IntPro &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Convert::DoublePro &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Convert::FloatPro &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
