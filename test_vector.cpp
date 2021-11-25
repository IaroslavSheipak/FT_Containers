#include "test_header.hpp"

void	vector_constructor_output_res(std::vector<int> &vec, std::string name) {
	std::cout << name << ": size = " << vec.size() << ", capacity = " << vec.capacity() << std::endl;
}

template< class T, class Alloc>
void output_vector(std::string name, std::vector<T, Alloc> &v) {
	std::cout << "\t" << name << " contains: ";
	for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	if (v.size() == 0)
		std::cout << "nothing";
	std::cout << "\n";
}


void vector_iterators(){
	std::cout << GREEN << "Vector iterator test:\n" << DEFAULT;
	std::vector<int>::iterator	iter;
	std::vector<int>::const_iterator	const_iter;
	
	const_iter=iter;
	std::cout << "vector<int>::iterator iter;\n"
				 "vector<int>::const_iterator const_iter;\n"
				 "const_iter = iter;\n";
	std::cout << "const_iter == iter: " << (iter == const_iter) << std::endl;
	++iter;
	iter++;
	--iter;
	iter--;
	iter + 5;
	5 + iter;
	iter - 5;
	iter - const_iter;
	const_iter - iter;
	iter += 5;
	iter -= 5;
	iter[5];
	std::cout << "\t++iter;\n"
				 "\titer++;\n"
				 "\t--iter;\n"
				 "\titer--;\n"
				 "\titer + 5;\n"
				 "\t5 + iter;\n"
				 "\titer - 5;\n"
				 "\titer - const_iter;\n"
				 "\tconst_iter - iter;\n"
				 "\titer += 5;\n"
				 "\titer -= 5;\n"
				 "\titer[5];\n";
	std::cout << "no errors -> good\n";

	std::cout << "ITERATORS RELATIONAL OPERATORS" << std::endl;
	std::cout << "iter < const_iter: " << (iter < const_iter) << std::endl;
	std::cout << "iter > const_iter: "<< (iter > const_iter) << std::endl;
	std::cout << "iter <= const_iter: "<< (iter <= const_iter) << std::endl;
	std::cout << "iter >= const_iter: "<< (iter >= const_iter) << std::endl;
	std::cout << "---------------------------------" << std::endl;

	std::cout << "\n";
}

void	vector_constructor() {
	std::cout << GREEN << "Constructors test:\n" << DEFAULT;

	// constructors used in the same order as described above
	std::vector<int> first;                                // empty vector of ints
	vector_constructor_output_res(first, "1) first()");

	std::vector<int> second (4, 100);                       // four ints with value 100
	vector_constructor_output_res(second, "2) second(4, 100)");
	output_vector("second", second);

	std::vector<int> third (second.begin(),second.end());  // iterating through second
	vector_constructor_output_res(third, "3) third(second.begin(),second.end())");
	output_vector("third", third);

	std::vector<int> fourth (third);                       // a copy of third
	vector_constructor_output_res(fourth, "4) fourth (third)");
	output_vector("fourth", fourth);

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	std::cout << "int myints[] = {16,2,77,29}\n";
	std::cout << "5) fifth (myints, myints + sizeof(myints) / sizeof(int) )\n";
	output_vector("fifth", fifth);

	std::cout << "\n";
}

void	vector_destructor() {
	std::cout << GREEN << "Destructor test:\n" << DEFAULT;

	std::vector<SampleClass> vec(5, SampleClass());
	std::cout << "vector<SampleClass> vec(5, SampleClass());\n";

	std::cout << "\tNo error and no leaks -> destructor is ok\n\n";
}

void	vector_operator_equal() {
	std::cout << GREEN << "Operator equal test:\n" << DEFAULT;

	std::vector<int> foo (3, 3);
	std::vector<int> bar (5, 5);

	bar = foo;
	foo = std::vector<int>();
	std::cout << "vector<int> foo (3, 3);\n"
				 "vector<int> bar (5, 5);\n"
				 "\nbar = foo;\n"
				 "foo = vector<int>();\n";

	vector_constructor_output_res(bar, "bar");
	output_vector("bar", bar);

	vector_constructor_output_res(foo, "foo");
	output_vector("foo", foo);

	std::cout << "\n";
}

void	vector_begin_end(){
	std::cout << GREEN << "Begin - End test:\n" << DEFAULT;

	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);
	std::cout << "for (int i=1; i<=5; i++) myvector.push_back(i);\n";

	output_vector("myvector", myvector);
	std::cout << "\n";
}

void	vector_rbegin_rend(){
	std::cout << GREEN << "Rbegin - Rend test:\n" << DEFAULT;

	std::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;
	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "int i=0;\n"
				 "vector<int>::reverse_iterator rit = myvector.rbegin();\n"
				 "for (; rit!= myvector.rend(); ++rit)\n"
				 "\t*rit = ++i;\n";

	output_vector("myvector", myvector);
	std::cout << "\n";
}

void	vector_size(){
	std::cout << GREEN << "Size() test:\n" << DEFAULT;

	std::vector<int> myints;
	std::cout << "vector<int> myints;\n";
	std::cout << "0. size: " << myints.size() << '\n';
	std::cout << "\n";
	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "for (int i=0; i<10; i++) myints.push_back(i);\n";
	std::cout << "1. size: " << myints.size() << '\n';
	std::cout << "\n";
	myints.insert (myints.end(), 10, 100);
	std::cout << "myints.insert (myints.end(), 10, 100);\n";
	std::cout << "2. size: " << myints.size() << '\n';
	std::cout << "\n";
	myints.pop_back();
	std::cout << "myints.pop_back();\n";
	std::cout << "3. size: " << myints.size() << '\n';
	std::cout << "\n";
}

void	vector_max_size_capacity() {
	std::cout << GREEN << "Max_size() and capacity() test:\n" << DEFAULT;
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++)
		myvector.push_back(i);
	std::cout << "Size, max_size and capacity after inserting 100 elems using push_back():\n";
	std::cout << "size:		=>" << myvector.size() << "\n";
	std::cout << "capacity:	=>" << myvector.capacity() << "\n";
	std::cout << "max_size:	=>" << myvector.max_size() << "\n";
	std::cout << "\n";
}


void	vector_resize() {
	std::cout << GREEN << "Resize test:\n" << DEFAULT;

	std::vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);
	std::cout << "vector<int> myvector;\n"
				 "for (int i = 1; i < 10; i++) myvector.push_back(i);\n"
				 "myvector.resize(5);\n"
				 "myvector.resize(8,100);\n"
				 "myvector.resize(12);\n";

	vector_constructor_output_res(myvector, "myvector");
	output_vector("myvector", myvector);
	std::cout << "\n";
}

void	vector_empty() {
	std::cout << GREEN << "Empty test:\n" << DEFAULT;

	std::vector<int> myvector;
	std::cout << "vector<int> myvector;\n";
	std::cout << "is empty: " << myvector.empty() << "\n";

	for (int i = 1; i <= 10; i++) myvector.push_back(i);
	std::cout << "for (int i = 1; i <= 10; i++) myvector.push_back(i);\n";
	std::cout << "is empty: " << myvector.empty() << "\n";

	myvector = std::vector<int>();
	std::cout << "myvector = vector<int>();\n";
	std::cout << "is empty: " << myvector.empty() << "\n\n";
}


void	vector_reserve(){
	std::cout << GREEN << "Reserve test:\n" << DEFAULT;

	std::vector<int>::size_type sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "vector<int>::size_type sz;\n"
				 "vector<int> foo;\n"
				 "sz = foo.capacity();\n";

	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
	if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "\tcapacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "vector<int> bar;\n"
				 "sz = bar.capacity();\n"
				 "bar.reserve(100);\n";

	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "\tcapacity changed: " << sz << '\n';
		}
	}
	std::cout << "\n";
}

void	vector_operator_brackets(){
	std::cout << GREEN << "Operator brackets test:\n" << DEFAULT;

	std::vector<int> myvector (10);   // 10 zero-initialized elements


	// assign some values:
	for (unsigned i = 0; i < myvector.size(); i++)
		myvector[i] = i;
	std::cout << "vector<int> myvector (10);\n"
				"for (unsigned i = 0; i < myvector.size(); i++)\n"
				"\tmyvector[i] = i;\n";

	output_vector("myvector", myvector);

	// reverse vector using operator[]:
	for (unsigned i = 0; i < myvector.size() / 2; i++)
	{
 		int temp = myvector[myvector.size() - 1 - i];
		myvector[myvector.size() - 1 - i] = myvector[i];
		myvector[i] = temp;
	}
	std::cout << "for (unsigned i = 0; i < myvector.size() / 2; i++) {\n"
				 "\tint temp = myvector[myvector.size() - 1 - i];\n"
				 "\tmyvector[myvector.size() - 1 - i] = myvector[i];\n"
				 "\tmyvector[i] = temp;\n"
				 "}\n";

	output_vector("myvector", myvector);
	std::cout << "\n";
}

void	vector_at(){
	std::cout << GREEN << "At test:\n" << DEFAULT;

	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;
	std::cout << "vector<int> myvector (10);\n"
				 "for (unsigned i=0; i<myvector.size(); i++)\n"
				 "\tmyvector.at(i)=i;\n";

	output_vector("myvector", myvector);

	std::cout << "try {\n"
				 "\tmyvector.at(100) = 1;\n"
				 "} catch(std::exception &e) {\n"
				 "\tstd::cout << e.what() << std::endl;\n"
				 "}\n";

	try {
		myvector.at(100) = 1;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
}

void vector_front(){
	std::cout << GREEN << "Front() test:\n" << DEFAULT;

	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();
	std::cout << "vector<int> myvector;\n"
				 "myvector.push_back(78);\n"
				 "myvector.push_back(16);\n"
				 "// now front equals 78, and back 16\n"
				 "myvector.front() -= myvector.back();\n";
	std::cout << "myvector.front() is now " << myvector.front() << "\n\n";
}


void vector_back(){
	std::cout << GREEN << "Back() test:\n" << DEFAULT;

	std::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0) {
		myvector.push_back ( myvector.back() -1 );
	}
	std::cout << "vector<int> myvector;\n"
				 "myvector.push_back(10);\n"
				 "while (myvector.back() != 0) {\n"
				 "\tmyvector.push_back ( myvector.back() -1 );\n"
				 "}\n";

	output_vector("myvector", myvector);
	std::cout << "\n";
}

void vector_assign() {
	std::cout << GREEN << "Assign test:\n" << DEFAULT;

	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7, 100);             // 7 ints with a value of 100
	std::cout << "vector<int> first;\n"
				 "vector<int> second;\n"
				 "vector<int> third;\n\n"
				 "first.assign (7, 100);\n";
	output_vector("first", first);

	second.assign (first.begin() + 1, first.end() - 1); // the 5 central values of first
	std::cout << "\nsecond.assign (first.begin() + 1, first.end() - 1);\n";
	output_vector("second", second);

	int myints[] = {1776,7,4};
	third.assign (myints, myints+3);   // assigning from array.
	std::cout << "\nint myints[] = {1776,7,4};\n"
				 "third.assign (myints, myints+3);\n";
	output_vector("third", third);
	std::cout << "\n";
}


void vector_push_back() {
	std::cout << GREEN << "Push_back test:\n" << DEFAULT;

	std::vector<int> myvector;

	for(int i = 0; i < 1000; i++)
		myvector.push_back (i);
	std::cout << "vector<int> myvector;\n"
				 "for(int i = 0; i < 1000; i++)\n"
				 "\tmyvector.push_back (i)\n";

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n\n";
}

void vector_pop_back(){
	std::cout << GREEN << "Pop_back test:\n" << DEFAULT;

	std::vector<int> myvector;
	int sum = 0;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty()) {
  		sum+=myvector.back();
  		myvector.pop_back();
	}
	std::cout << "vector<int> myvector;\n"
				 "int sum = 0;\n"
				 "myvector.push_back (100);\n"
				 "myvector.push_back (200);\n"
				 "myvector.push_back (300);\n"
				 "while (!myvector.empty()) {\n"
				 "\tsum+=myvector.back();\n"
				 "\tmyvector.pop_back();\n"
				 "}\n";

	std::cout << "The elements of myvector add up to " << sum << "\n\n";

}

void vector_insert() {
	std::cout << GREEN << "Insert test:\n" << DEFAULT;

	std::vector<int> myvector (3, 100);
	std::vector<int>::iterator it;

	it = myvector.insert (myvector.begin(), 200);
	std::cout << "vector<int> myvector (3, 100);\n"
				 "vector<int>::iterator it;\n"
				 "it = myvector.insert (myvector.begin(), 200);\n";
	output_vector("myvector", myvector);

	myvector.insert (it, 2, 300);
	std::cout << "\nmyvector.insert (it, 2, 300);\n";
	output_vector("myvector", myvector);

	// "it" no longer valid, get a new one:
	it = myvector.begin();
	std::vector<int> anothervector (2, 400);
	myvector.insert (it + 2, anothervector.begin(), anothervector.end());
	std::cout << "\n// it no longer valid, get a new one:\n"
				 "it = myvector.begin();\n"
				 "vector<int> anothervector (2, 400);\n"
				 "myvector.insert (it + 2, anothervector.begin(), anothervector.end());\n";
	output_vector("myvector", myvector);

	int myarray [] = { 501, 502, 503 };
	myvector.insert (myvector.begin(), myarray, myarray + 3);
	std::cout << "\nint myarray [] = { 501, 502, 503 };\n"
				 "myvector.insert (myvector.begin(), myarray, myarray + 3);\n";
	output_vector("myvector", myvector);

	std::cout << "\n";
}

void vector_erase() {
	std::cout << GREEN << "Erase test:\n" << DEFAULT;

	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++) myvector.push_back(i);
	std::cout << "vector<int> myvector;\n"
				 "for (int i = 1; i <= 10; i++) myvector.push_back(i);\n";
	output_vector("myvector", myvector);

	// erase the 6th element
	myvector.erase (myvector.begin() + 5);
	std::cout << "myvector.erase (myvector.begin() + 5);\n";
	output_vector("myvector", myvector);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(), myvector.begin() + 3);
	std::cout << "myvector.erase (myvector.begin(), myvector.begin() + 3);\n";
	output_vector("myvector", myvector);

	std::cout << "\n";
}

void vector_swap(){
	std::cout << GREEN << "Swap test:\n" << DEFAULT;

	std::vector<int> foo (3, 100);   // three ints with a value of 100
	std::vector<int> bar (5, 200);   // five ints with a value of 200

	foo.swap(bar);
	std::cout << "vector<int> foo (3, 100);   // three ints with a value of 100\n"
				 "vector<int> bar (5, 200);   // five ints with a value of 200\n"
				 "foo.swap(bar);\n";

	output_vector("foo", foo);
	output_vector("bar", bar);

	std::cout << "\n";
}

void vector_clear() {
	std::cout << GREEN << "Clear test:\n" << DEFAULT;

	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	std::cout << "vector<int> myvector;\n"
				 "myvector.push_back (100);\n"
				 "myvector.push_back (200);\n"
				 "myvector.push_back (300);\n";
	output_vector("myvector", myvector);


	myvector.clear();
	std::cout << "myvector.clear();\n";
	output_vector("myvector", myvector);

	myvector.push_back (1101);
	myvector.push_back (2202);
	std::cout << "myvector.push_back (1101);\n"
				 "myvector.push_back (2202);\n";
	output_vector("myvector", myvector);

	std::cout << "\n";
}

void vector_get_allocator(){
	std::cout << GREEN << "Get_allocator() test:\n" << DEFAULT;

	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i], i);

	std::cout << "vector<int> myvector;\n"
				 "int * p;\n"
				 "unsigned int i;\n"
				 "p = myvector.get_allocator().allocate(5);\n"
				 "for (i = 0; i < 5; i++)\n"
				 "\tmyvector.get_allocator().construct(&p[i], i);\n";

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);
	std::cout << "for (i = 0; i < 5; i++)\n"
				 "\tmyvector.get_allocator().destroy(&p[i]);\n"
				 "myvector.get_allocator().deallocate(p, 5);\n\n";
}

void vector_relational_operators() {
	std::cout << GREEN << "Relational operators test:\n" << DEFAULT;

	std::vector<int> foo (3, 100);   // three ints with a value of 100
	std::vector<int> bar (2, 200);   // two ints with a value of 200
	std::cout << "vector<int> foo (3, 100);\n"
				 "vector<int> bar (2, 200);\n\n";
	std::cout << "foo == bar: "	<< (foo == bar) << std::endl;
	std::cout << "foo != bar: "	<< (foo != bar) << std::endl;
	std::cout << "foo >  bar: "	<< (foo > bar) << std::endl;
	std::cout << "foo <  bar: "	<< (foo < bar) << std::endl;
	std::cout << "foo >= bar: "	<< (foo >= bar) << std::endl;
	std::cout << "foo <= bar: "	<< (foo <= bar) << std::endl;
	std::cout << "\n";
}

void vector_swap_nonmb() {
	std::cout << GREEN << "Swap nonmember test:\n" << DEFAULT;

	std::vector<int> foo (3, 100);   // three ints with a value of 100
	std::vector<int> bar (5, 200);   // five ints with a value of 200

	std::cout << "vector<int> foo (3, 100);\n"
				"vector<int> bar (5, 200);\n";

	vector_constructor_output_res(foo, "foo");
	output_vector("foo", foo);
	vector_constructor_output_res(bar, "bar");
	output_vector("bar", bar);

	std::swap(foo, bar);
	std::cout << "\nstd::swap(foo, bar);\n";
	vector_constructor_output_res(foo, "foo");
	output_vector("foo", foo);
	vector_constructor_output_res(bar, "bar");
	output_vector("bar", bar);

  	std::cout << "\n";
}


void vector_push_back_performance() {
	std::vector<int> vec;
	for (int i = 0; i < 300; i++)
		vec.push_back(i);
}

void vector_insert_val_performance() {
	std::vector<int> vec;
	for (int i = 0; i < 100; i++) {
		vec.insert(vec.begin(), i);
	}
	for (int i = 0; i < 100; i++) {
		vec.insert(vec.begin() + 50, i);
	}
}

void vector_insert_fill_performance() {
	std::vector<int> vec;
	for (int i = 0; i < 100; i++) {
		vec.insert(vec.begin(), 30, i);
	}
	for (int i = 0; i < 100; i++) {
		vec.insert(vec.begin() + 50, 30, i);
	}
}

void vector_insert_iterator_performance() {
	std::vector<int> vec;
	int myints[] = {16, 2, 77, 29, 11, 15, 221};
	for (size_t i = 0; i < 100; ++i)
		vec.insert(vec.begin(), myints, myints + sizeof(myints) / sizeof(int));
	for (size_t i = 0; i < 100; ++i)
		vec.insert(vec.begin() + 100, myints, myints + sizeof(myints) / sizeof(int));
}

void vector_erase_pos_performance() {
	std::vector<int> vec(1000, 2);
	for (size_t i = 0; i < 100; ++i)
		vec.erase(vec.begin() + 100);
	for (size_t i = 0; i < 100; ++i)
		vec.erase(vec.begin());
}

void vector_erase_iterator_performance() {
	std::vector<int> vec(500, 2);
	for (size_t i = 0; i < 20; ++i)
		vec.erase(vec.begin() + 30, vec.begin() + 40);
	for (size_t i = 0; i < 20; ++i)
		vec.erase(vec.begin(), vec.begin() + 10);
}

void vector_reserve_performance() {
	std::vector<int> vec(50, 1);
	for (size_t i = 0; i < 20; ++i)
		vec.reserve(vec.capacity() * 2);
}

void vector_resize_performance() {
	std::vector<int> vec(50, 1);
	for (size_t i = 0; i < 10; ++i)
		vec.resize(vec.capacity() * 2);
	for (size_t i = 0; i < 10; ++i)
		vec.resize(vec.size() - 10);
}

void vector_assign_val_performance() {
	std::vector<int> vec(50, 1);
	for (size_t i = 1; i < 30; ++i)
		vec.assign(i * 2, i);
	for (size_t i = 30; i > 0; --i)
		vec.assign(i, i);
}

void vector_assign_iterator_performance() {
	std::vector<int> basic(200, 1);
	std::vector<int> vec;
	for (size_t i = 0; i < 100; ++i)
		vec.assign(basic.begin(), basic.begin() + (i * 2));
}
