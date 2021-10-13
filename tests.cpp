#include "vector/Vector.hpp"
#include <iostream>
#include <algorithm>
#include "vector/Vector.hpp"


struct NoDefaultConstructor{
		NoDefaultConstructor();
		~NoDefaultConstructor(){};
};

void	test_reserve(){
	ft::vector<NoDefaultConstructor> vec;

	try{
		vec.reserve(-1);
	} catch (std::exception &a){
		std::cout << a.what() << std::endl;
	}

}

int main()
{
	ft::vector<int> a(5);
	//a[0] = 42;
	

	test_reserve();
	//a.push_back(2);
	//a.push_back(3);
	//std::sort(++a.begin(), a.end());
	std::cout << a[0] << std::endl;
	return (0);
}
