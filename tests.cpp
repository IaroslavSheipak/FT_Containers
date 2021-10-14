#include "../ft_containers/vector/vector.hpp"
#include <vector>
#include <iostream>
#include <algorithm>


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
		vec.reserve(1);
		return;
	} catch (std::exception &a){
		std::cout << a.what() << std::endl;
	}
}

//void test_insert(){
//
//	ft::vector<int> vec;
//
//	vec.insert(vec.begin(), 1);
//	vec.insert(vec.begin() + 1, 2);
//	std::cout << vec[0] << std::endl;
//	std::cout << vec[1] << std::endl;
//
//}

void test_iterators(){

	std::vector<int>			vec;
	std::vector<int>::iterator	iter;

	iter = vec.begin();
}

void test_insert()
{
	std::vector<int> v(10);
	v.insert(v.end() + 2, 2, 3);
	v[5] = 2;
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;
	std::cout << v.size() << std::endl;
}

void	test_erase() {
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
	
	test_erase();
	//test_reserve();
	//test_insert();
	return (0);
}
