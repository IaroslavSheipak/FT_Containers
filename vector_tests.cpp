#ifdef yarik
#include "../ft_containers/vector/Vector.hpp"
#include "../ft_containers/iterator/iterator.hpp"
#endif
#ifdef kirill
#include "../ft_containers/stack/stack.hpp"
#endif
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
# define B_CYAN "\x1b[46;1m" <<
# define B_RED  "\x1b[41;1m" <<
# define YELLOW "\x1b[33;1m" <<
# define RED    "\x1b[31;1m" <<
# define GREEN  "\x1b[32;1m" <<
# define DEFAULT << "\x1b[m"

//struct NoDefaultConstructor{
//		NoDefaultConstructor & operator=(NoDefaultConstructor & src);
//		NoDefaultConstructor();
//		~NoDefaultConstructor(){};
//};

void time(clock_t end, clock_t start){
	
	std::cout << GREEN end - start << std::endl DEFAULT;
}

void who_won(std::string name_of_test, clock_t my_dur, clock_t stl_dur) {
	std::cout << name_of_test << "!!!!!!!!!!!" << std::endl;
	std::cout << std::fixed << "stl vector: " << stl_dur << std::endl;
	std::cout << std::fixed << "your vector: " << my_dur << std::endl;
	double res = my_dur / stl_dur;
	std::cout << std::fixed << "your_res = " << res << " stl_res, ";
	if (res <= 1)
		std::cout << "you won :-)\n";
	else
		std::cout << "stl won :-(\n";
}


void test_reserve() {
	std::vector<int> v1(50, 2);
	ft::vector<int> v2(50, 2);
	clock_t start, end;

	start = clock();
	v1.reserve(100);
	end = clock();
	clock_t stl_duration = end - start;

	start = clock();
	v2.reserve(100);
	end = clock();
	clock_t my_duration = end - start;

	who_won("RESERVE TEST" , my_duration, stl_duration);
}

void test_push_back() {
	ft::vector<int> v1;
	ft::vector<int> v2;

	for (int i = 0; i < 40; i++)
		v1.push_back(i);

}

void test_pop_back() {
	ft::vector<int> v1(50, 2);

	for (int i = 0; i < 40; i++)
		v1.pop_back();

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



void test_insert(){

	std::vector<int> std_vec;
	ft::vector<int> ft_vec;
	clock_t start, end;
	clock_t ft_time, std_time;

	start = clock();
	for (int i = 0; i < 40000; i++)
		std_vec.insert(std_vec.begin(), 1);
	end = clock();
	std_time = end - start;
	time(end, start);
	std::cout << "std vec time:" << std_time << std::endl;
	start = clock();
	for (int i = 0; i < 40000; i++)
		ft_vec.insert(ft_vec.begin(), 1);
	end = clock();
	ft_time = end - start;
	time(end, start);
	std::cout << "ft vec time:" << ft_time << std::endl;
	std::cout << "\033[1;31myour vec is slower as " << ft_time / std_time << " \033[0m"<< std::endl;
}






template<class Iter, class ConstIter>
void test_iterators(Iter iter, ConstIter const_iter){
	
//
//	ft::vector<int>::iterator	iter;
//	ft::vector<int>::const_iterator	const_iter;
	
	const_iter=iter;
	assert(iter == const_iter);
	//std::cout << *iter << std::endl;
	//*iter = 5;
	++iter;
	iter++;
	//*iter++;
	--iter;
	iter--;
	//*iter--;
	iter + 5;
	5 + iter;
	iter - 5;
	iter - const_iter;
	const_iter - iter;
	assert(iter < const_iter);
	assert(iter > const_iter);
	assert(iter <= const_iter);
	assert(iter >= const_iter);
	iter += 5;
	iter -= 5;
	iter[5];
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
	
	test_iterators(ft::vector<int>::iterator(), ft::vector<int>::const_iterator());
	test_iterators(std::vector<int>::iterator(), std::vector<int>::const_iterator());
	
	//test_reserve();
	//test_reverse();}}
	//test_insert();
	return (0);
}
