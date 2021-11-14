
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

class SampleClass{
	public:
		SampleClass(){
			_nums = new int[4];
		}
		SampleClass(SampleClass const & src){
			_nums = new int[4];
			for (int i = 0; i < 4; i++){
				_nums[i] = src._nums[i];
			}
		}
		SampleClass & operator=(SampleClass & src){
			delete [] _nums;
			_nums = new int[4];
			for (int i = 0; i < 4; i++){
				_nums[i] = src._nums[i];
			}
			return (*this);
		}
		~SampleClass(){
			delete [] _nums;
		}

	private:
		int *_nums;
};

void time(clock_t end, clock_t start){
	
	std::cout << GREEN end - start << std::endl DEFAULT;
}

void who_won(std::string name_of_vector, clock_t my_dur, clock_t stl_dur) {
	std::cout << name_of_vector << "!!!!!!!!!!!" << std::endl;
	std::cout << std::fixed << "stl vector: " << stl_dur << std::endl;
	std::cout << std::fixed << "your vector: " << my_dur << std::endl;
	double res = my_dur / stl_dur;
	std::cout << std::fixed << "your_res = " << res << " stl_res, ";
	if (res <= 1)
		std::cout << "you won :-)\n";
	else
		std::cout << "stl won :-(\n";
}


void	vector_constructor(){
	// constructors used in the same order as described above
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	 std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vector_destructor(){

	ft::vector<SampleClass> vec(5, SampleClass());
}

void	vector_operator_equal(){
	ft::vector<int> foo (3,0);
	ft::vector<int> bar (5,0);

	bar = foo;
	foo = ft::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void	vector_begin_end(){
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vector_rbegin_rend(){
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
	*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vector_size(){
	ft::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void	vector_max_size_capacity(){

	ft::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}


void	vector_resize(){

	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vector_empty(){
	ft::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "total: " << sum << '\n';
}


void	vector_reserve(){
ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
	if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void	vector_operator_brackets(){

	ft::vector<int> myvector (10);   // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
 		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vector_at(){
	ft::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';	
}

void vector_front(){

	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();
	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}


void vector_back(){
	ft::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
  		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_assign(){
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}


void vector_push_back()
{
  ft::vector<int> myvector;
  int myint = 1000;


  for(int i = 0; i < myint; i++)
	myvector.push_back (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

void vector_pop_back(){
	ft::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
  		sum+=myvector.back();
  		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';

}

void vector_insert(){
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void vector_erase(){
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_swap(){
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void vector_clear(){
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_get_allocator(){
	ft::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void vector_relational_operators(){
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void vector_swap_nonmb(){
	unsigned int i;
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
}
//void vector_reserve() {
//	ft::vector<int> v1(50, 2);
//	ft::vector<int> v2(50, 2);
//	clock_t start, end;
//
//	start = clock();
//	v1.reserve(100);
//	end = clock();
//	clock_t stl_duration = end - start;
//
//	start = clock();
//	v2.reserve(100);
//	end = clock();
//	clock_t my_duration = end - start;
//
//	who_won("RESERVE vector" , my_duration, stl_duration);
//}

//void vector_push_back() {
//	ft::vector<int> v1;
//	ft::vector<int> v2;
//
//	for (int i = 0; i < 40; i++)
//		v1.push_back(i);
//
//}
//
//void vector_pop_back() {
//	ft::vector<int> v1(50, 2);
//
//	for (int i = 0; i < 40; i++)
//		v1.pop_back();
//
//}
//

template<class A, class B>
void compare_assert(A stdv1, A stdv2, B v1, B v2, std::string name) {
	assert((stdv1 == stdv2) == (v1 == v2) && (stdv1 != stdv2) == (v1 != v2));
	assert((stdv1 > stdv2) == (v1 > v2) && (stdv1 < stdv2) == (v1 < v2));
	assert((stdv1 >= stdv2) == (v1 >= v2) && (stdv1 <= stdv2) == (v1 <= v2));
	std::cout << "'" << name << "'is ok\n";
}


void vector_vec_comparison() {
	ft::vector<int> stdv1;
	ft::vector<int> stdv2;
	ft::vector<int> v1;
	ft::vector<int> v2;

	compare_assert(stdv1, stdv2, v1, v2, "all is empty");

	stdv1 = ft::vector<int>(3, 4);
	stdv2 = ft::vector<int>(stdv1.begin(), stdv1.end());
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
//void	vector_reserve(){
//	ft::vector<NoDefaultConstructor> vec;
//	try{
//		vec.reserve(1);
//		return;
//	} catch (std::exception &a){
//		std::cout << a.what() << std::endl;
//	}
//}
//



//void vector_insert(){
//
//	ft::vector<int> std_vec;
//	ft::vector<int> ft_vec;
//	clock_t start, end;
//	clock_t ft_time, std_time;
//
//	start = clock();
//	for (int i = 0; i < 40000; i++)
//		std_vec.insert(std_vec.begin(), 1);
//	end = clock();
//	std_time = end - start;
//	time(end, start);
//	std::cout << "std vec time:" << std_time << std::endl;
//	start = clock();
//	for (int i = 0; i < 40000; i++)
//		ft_vec.insert(ft_vec.begin(), 1);
//	end = clock();
//	ft_time = end - start;
//	time(end, start);
//	std::cout << "ft vec time:" << ft_time << std::endl;
//	std::cout << "\033[1;31myour vec is slower as " << ft_time / std_time << " \033[0m"<< std::endl;
//}






template<class Iter, class ConstIter>
void vector_iterators(Iter iter, ConstIter const_iter){
	
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
	std::cout << "ITERATORS RELATIONAL OPERATORS" << std::endl;
	std:: cout << (iter < const_iter) << std::endl;
	std::cout << (iter > const_iter) << std::endl;
	std::cout << (iter <= const_iter) << std::endl;
	std::cout << (iter >= const_iter) << std::endl;
	std::cout << "---------------------------------" << std::endl;
	
	iter += 5;
	iter -= 5;
	iter[5];
}

//void	vector_erase() {
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


void test_vector(){

	vector_constructor();
	vector_destructor();
	vector_begin_end();
	vector_rbegin_rend();
	vector_size();
	vector_max_size_capacity();
	vector_empty();
	vector_reserve();
	vector_operator_brackets();
	vector_at();
	vector_front();
	vector_back();
	vector_assign();
	vector_push_back();
	vector_pop_back();
	vector_insert();
	vector_erase();
	vector_swap();
	vector_clear();
	vector_get_allocator();
	vector_relational_operators();
	vector_swap();	
}


int main()
{
	
	vector_iterators(ft::vector<int>::iterator(), ft::vector<int>::const_iterator());
	vector_iterators(ft::vector<int>::iterator(), ft::vector<int>::const_iterator());

	test_vector();	
	//vector_reserve();
	//vector_reverse();
	//vector_insert();
	return (0);
}
