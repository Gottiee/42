#include "../header/easyfind.hpp"

int main(void)
{
	std::cout << "---Vector test---\n\n";
	int myints[] = {16,2,77,29};
	std::vector<int> 					vec(myints, myints + sizeof(myints) / sizeof(int) );
	std::vector<int>::iterator	it;

	it = easyfind<std::vector<int> >(vec, 77);
	std::cout << *it << std::endl;
	it = easyfind<std::vector<int> >(vec, 78);
	it = easyfind<std::vector<int> >(vec, 29);
	std::cout << *it << std::endl;

	std::cout << "---List test---\n\n";
	int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
	std::list<int> 				li(arr, arr + n);
	std::list<int>::iterator	it_l;	

	it_l = easyfind<std::list<int> >(li, 20);
	std::cout << *it_l << std::endl;
	it_l = easyfind<std::list<int> >(li, 11);
}
