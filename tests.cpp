#include "../ft_containers/vector/Vector.hpp"
//#include "../ft_containers/iterator/iterator.hpp"
#include <vector>
#include <iostream>
#include <algorithm>


//struct NoDefaultConstructor{
//		NoDefaultConstructor & operator=(NoDefaultConstructor & src);
//		NoDefaultConstructor();
//		~NoDefaultConstructor(){};
//};
//
//template<class T, class Allocator = std::allocator<T> >
//void output_vector(const ft::vector<T, Allocator> &v) {
//	for (size_t i = 0; i < v.size(); i++)
//		std::cout << v[i] << " ";
//	std::cout << std::endl;
//}
//
//void	test_reserve(){
//	std::vector<NoDefaultConstructor> vec;
//	try{
//		vec.reserve(1);
//		return;
//	} catch (std::exception &a){
//		std::cout << a.what() << std::endl;
//	}
//}
//
//void test_insert(){
//
//	ft::vector<int> vec;
//
//	vec.insert(vec.capacity(), 1, 1);
//
//}
//
void test_iterators(){
	
//	std::vector<int>::iterator iter;
//	std::vector<int>::const_iterator const_iter;
//
	ft::vector<int>::iterator	iter;
	ft::vector<int>::const_iterator	const_iter;
	
	iter = const_iter;
	const_iter = iter;
//	assert(iter == const_iter);
//	assert(iter != const_iter);
//	std::cout << *iter << std::endl;
//	//iter->m
//	*iter = 5;
//	++iter;
//	iter++;
//	*iter++;
//	--iter;
//	iter--;
//	*iter--;
//	iter + 5;
//	5 + iter;
//	iter - 5;
//	iter - const_iter;
//	iter < const_iter;
//	iter > const_iter;
//	iter <= const_iter;
//	iter >= const_iter;
//	iter += 5;
//	iter -= 5;
//	iter[5];
//
	


	


}

//void	test_erase() {
//	ft::vector<int> v(10);
//	for (size_t i = 0; i < v.size(); i++)
//		v[i] = i;
//	try {
//		std::cout << "vector before erasing:\n";
//		output_vector(v);
//		v.erase(v.begin() - 100);
//		std::cout << "vector after erasing:\n";
//		output_vector(v);
//	} catch (std::exception &e) {
//		std::cout << "some error happened: " << e.what() << std::endl;
//	}
//}


int main()
{
	
	test_iterators();
	//test_reserve();
	//test_insert();
	return (0);
}
