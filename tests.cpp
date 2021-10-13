#include "vector/Vector.hpp"
#include <iostream>
#include <algorithm>
#include "vector/Vector.hpp"


struct NoDefaultConstructor{
		NoDefaultConstructor();
		~NoDefaultConstructor(){};
};

template<class T, class Allocator = std::allocator<T> >
void output_vector(const ft::vector<T, Allocator> &v) {
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void	test_reserve(){
	ft::vector<NoDefaultConstructor> vec;

	try{
		vec.reserve(-1);
	} catch (std::exception &a){
		std::cout << a.what() << std::endl;
	}
}

void test_erase() {
	ft::vector<int> v(10);
	for (size_t i = 0; i < v.size(); i++)
		v[i] = i;
	try {
		std::cout << "vector before erasing:\n";
		output_vector(v);
		v.erase(v.begin() - 100);
		std::cout << "vector after erasing:\n";
		output_vector(v);
	} catch (std::exception &e) {
		std::cout << "some error happened: " << e.what() << std::endl;
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
