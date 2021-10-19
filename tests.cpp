#include "../ft_containers/vector/Vector.hpp"
//#include "../ft_containers/iterator/iterator.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

void who_won(std::string name_of_test, std::chrono::duration<double> my_dur, std::chrono::duration<double> stl_dur) {
	std::cout << name_of_test << "!!!!!!!!!!!" << std::endl;
	std::cout << std::fixed << "stl vector: " << stl_dur.count() << std::endl;
	std::cout << std::fixed << "your vector: " << my_dur.count() << std::endl;
	double res = my_dur / stl_dur;
	std::cout << std::fixed << "your_res = " << res << " stl_res, ";
	if (res <= 1)
		std::cout << "you won :-)\n";
	else
		std::cout << "stl won :-(\n";
}

void test_push_back() {
	std::vector<int> v1;
	ft::vector<int> v2;
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 40; i++)
		v1.push_back(i);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> stl_duration = end - start;

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 40; i++)
		v2.push_back(i);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> my_duration = end - start;

	who_won("PUSH_BACK TEST" , my_duration, stl_duration);
}

void test_pop_back() {
	std::vector<int> v1(50, 2);
	ft::vector<int> v2(50, 2);
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 40; i++)
		v1.pop_back();
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> stl_duration = end - start;

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 40; i++)
		v2.pop_back();
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> my_duration = end - start;

	who_won("POP_BACK TEST" , my_duration, stl_duration);
}

void test_reserve() {
	std::vector<int> v1(50, 2);
	ft::vector<int> v2(50, 2);
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<double> > start, end;

	start = std::chrono::high_resolution_clock::now();
	v1.reserve(100);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> stl_duration = end - start;

	start = std::chrono::high_resolution_clock::now();
	v2.reserve(100);
	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> my_duration = end - start;

	who_won("RESERVE TEST" , my_duration, stl_duration);
}

template<class A, class B>
void compare_assert(A stdv1, A stdv2, B v1, B v2, std::string name) {
	assert((stdv1 == stdv2) == (v1 == v2) && (stdv1 != stdv2) == (v1 != v2));
	assert((stdv1 > stdv2) == (v1 > v2) && (stdv1 < stdv2) == (v1 < v2));
	assert((stdv1 >= stdv2) == (v1 >= v2) && (stdv1 <= stdv2) == (v1 <= v2));
	std::cout << "'" << name << "'is ok\n";
}


void test_vec_comparison() {
	std::vector<int> stdv1;
	std::vector<int> stdv2;
	ft::vector<int> v1;
	ft::vector<int> v2;

	compare_assert(stdv1, stdv2, v1, v2, "all is empty");

	stdv1 = std::vector<int>(3, 4);
	stdv2 = std::vector<int>(stdv1.begin(), stdv1.end());
	v1 = ft::vector<int>(stdv1.begin(), stdv1.end());
	v2 = ft::vector<int>(stdv1.begin(), stdv1.end());

	compare_assert(stdv1, stdv2, v1, v2, "all is not empty but is equal");

	stdv2.insert(stdv2.end(), stdv1.begin(), stdv1.end());
	v2.assign(stdv2.begin(), stdv2.end());

	compare_assert(stdv1, stdv2, v1, v2, "all is not empty and is not equal");

	std::cout << "Comparison is ok\n";
}

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
