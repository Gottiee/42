#include "../header/MutantStack.hpp"

int main(void)
{
	std::cout << "--MutantStack test--\n\n";
	{
		MutantStack<int> mstack;
	
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);	
	
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n--list test--\n\n";
	{
		std::list<int> mstack;

		mstack.push_back(5);//modified
		mstack.push_back(17);
		std::cout << *(--mstack.end()) << std::endl;
		mstack.pop_back();// modifed
		std::cout << mstack.size() << std::endl;
	
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);	
	
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}
