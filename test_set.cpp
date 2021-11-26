#include "test_header.hpp"

#include  "test_header.hpp"


template<class T, class Comp, class Alloc>
void output_set(std::string name, std::set<T, Comp, Alloc> &s) {
	std::cout << name << " contains:\n";
	for (typename std::set<T>::iterator it = s.begin(); it != s.end(); ++it)
		std::cout << "\t=> " << *it<< '\n';
	if (s.size() == 0)
		std::cout << "\tnothing\n";
}

void set_iterators(){
	std::cout << GREEN << "Set iterator test:\n" << DEFAULT;

	std::set<int> s;
	for (int i = 0; i < 2; ++i)
		s.insert(i);

	std::set<int>::iterator it = s.begin();
	std::set<int>::const_iterator it2 = it;
	std::cout << "set<int> s;\n"
				 "for (int i = 0; i < 2; ++i)\n"
				 "\ts.insert(i);\n"
				 "set<int>::iterator it = s.begin();\n"
				 "set<int>::const_iterator it2 = it;\n";
	std::cout << "it == it2: " << (it == it2) << std::endl;
	it++;
	std::cout << "it++;\n";
	std::cout << "it == it2: " << (it == it2) << std::endl;
	--it;
	std::cout << "--it;\n";
	std::cout << "it == it2: " << (it == it2) << std::endl;
	++it2;
	it2--;
	std::cout << "++it2;\nit2--;\n";
	std::cout << "it == it2: " << (it == it2) << std::endl;
	it2 = it;
	//it = it2;  // it doesn't work

	std::cout << "\n";
}

void	set_constructor()
{
	std::cout << GREEN << "Constructor test:\n" << DEFAULT;
	std::cout << "1)set<char> first;\n"
				 "for (char i = 'a', i < 'e', ++i)\n"
				 "\tfirst.insert(i);\n";
	std::set<char> first;
	for (char i = 'a'; i < 'e'; ++i)
		first.insert(i);
	output_set("first", first);
	std::cout << "\n";

	std::set<char> second (first.begin(),first.end());
	std::cout << "2)set<char> second (first.begin(),first.end());\n";
	output_set("second", second);
	std::cout << "\n";

	std::set<char> third (second);
	std::cout << "3)set<char> third (second);\n";
	output_set("third", third);
	std::cout << "\n";

//	std::set<char, classcomp> fourth;                 // class as Compare
//	std::cout << "4)set<char, classcomp> fourth;\n";
//
//	bool(*fn_pt)(char,char) = fncomp;
//
//	std::set<char, bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
//	std::cout << "\tbool(*fn_pt)(char,char) = fncomp;\n";
//	std::cout << "5)set<char, bool(*)(char,char)> fifth (fn_pt);\n";
	std::cout << "\n";
}


void set_destructor(){
	std::cout << GREEN << "Destructor test:\n" << DEFAULT;
	std::set<int> s;
	for (int i = 0; i < 5; i++)
		s.insert(i);
	std::cout << "set<SampleClass> s;\n"
				 "for (int i = 0; i < 5; i++)\n"
				 "\ts.insert(SampleClass());\n";

	std::cout << "No errors and no leaks -> all is ok\n\n";
}

void set_operator_equals(){
	std::cout << GREEN << "Operator equals test:\n" << DEFAULT;
	std::set<char> first;
	std::set<char> second;

	for (char i = 'x'; i != 'z'; ++i)
		first.insert(i);
	std::cout <<    "set<char> first;\n"
					"set<char> second;\n"
					"for (char i = 'x'; i != 'z'; ++i)\n"
					"\tfirst.insert(i);\n"
					"second = first;\n";
	second = first;                // second now contains 3 ints
	std::cout << "first == second: " << (first == second) << "\n";
	output_set("second", second);
	std::cout << "\n";

	std::cout << "Size of first: " << first.size() << '\n';
	first = std::set<char>();  // and first is now empty
	std::cout << "first = set<char>();\n";
	output_set("first", first);
	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << "\n\n";
}

void set_begin_end(){
	std::cout << GREEN << "Begin - end test:\n" << DEFAULT;

	std::set<char> myset;

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);
	std::cout << "set<char> myset;\n"
				 "for (char i = 'a'; i < 'd'; ++i)\n"
				 "\tmyset.insert(i);\n";

	// show content:
	std::cout << "for (<char>::iterator it = myset.begin(); it != myset.end(); ++it)\n";
	for (std::set<char>::iterator it = myset.begin(); it != myset.end(); ++it)
		std::cout << "\t=>" << *it << "\n";
	std::cout << "\n";
}

void set_rbegin_rend(){
	std::cout << GREEN << "Rbegin - rend test:\n" << DEFAULT;

	std::set<char> myset;

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);
	std::cout << "set<char> myset;\n"
				 "for (char i = 'a'; i < 'd'; ++i)\n"
				 "\tmyset.insert(i);\n";

	// show content:
	std::cout << "for (rit=myset.rbegin(); rit!=myset.rend(); ++rit)\n";
	std::set<char>::reverse_iterator rit;
	for (rit=myset.rbegin(); rit!=myset.rend(); ++rit)
		std::cout << "\t=>" << *rit << "\n";
	std::cout << "\n";
}

void set_empty(){
	std::cout << GREEN << "Empty test:\n" << DEFAULT;

	std::set<char> myset;

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);
	std::cout << "set<char> myset;\n"
				 "for (char i = 'a'; i < 'd'; ++i)\n"
				 "\tmyset.insert(i);\n";

	std::cout << "while is not empty: show begin and then erase begin\n";
	while (!myset.empty())
	{
		std::cout << "\t=>" << *myset.begin() << '\n';
		myset.erase(myset.begin());
	}
	std::cout << "\n";
}

void set_size(){
	std::cout << GREEN << "Size test:\n" << DEFAULT;

	std::set<char> myset;
	std::cout << "set<char> myset;\n";
	std::cout << "\tmyset.size() is " << myset.size() << '\n';
	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);
	std::cout << "set<char> myset;\n"
				 "for (char i = 'a'; i < 'd'; ++i)\n"
				 "\tmyset.insert(i);\n";

	std::cout << "\tmyset.size() is " << myset.size() << '\n';
	std::cout << "\n";
}

void set_max_size(){
	std::cout << GREEN << "Max size test:\n" << DEFAULT;
	std::set<int> myset;

	std::cout << "If myset.max_size() > 1000: insert 1000 elements\n";
	if (myset.max_size() > 1000)
	{
		for (int i = 0; i < 1000; i++)
			myset.insert(i);
		std::cout << "The set contains 1000 elements.\n";
	}
	else
		std::cout << "The myset could not hold 1000 elements.\n";
	std::cout << "\n";

}


void set_insert(){
	std::cout << GREEN << "Insert test:\n" << DEFAULT;
	std::set<int> myset;
	std::set<int>::iterator it;
	// first insert function version (single parameter):
	std::cout << "first insert function version (single parameter):\n";
	myset.insert ( 1 );
	myset.insert ( 2 );
	std::cout <<"set<int> myset;\n"
				"\tmyset.insert ( 1 );\n"
				"\tmyset.insert ( 2 );\n"
				"ret = myset.insert ( 2 );\n";

	std::pair<std::set<int>::iterator,bool> ret;
	ret = myset.insert ( 2 );
	if (ret.second==false) {
		std::cout << "element '2' already existed\n";
	}
	else
		std::cout << "element '2' was successfully inserted\n";
	output_set("myset", myset);

	// second insert function version (with hint position):
	std::cout << "\nsecond insert function version (with hint position):\n";
	it = myset.begin();
	myset.insert (it, 3);  // max efficiency inserting
	myset.insert (it, 4);  // no max efficiency inserting
	std::cout << "it = myset.begin();\n"
				 "\tmyset.insert (it, 3);\n"
				 "\tmyset.insert (it, 4);\n";
	output_set("myset", myset);

	// third insert function version (range insertion):
	std::cout << "\nthird insert function version (range insertion):\n";
	std::set<int> anotherset;
	anotherset.insert(myset.begin(), myset.find(3));
	std::cout << "set<int> anotherset;\n"
				 "\tanotherset.insert(myset.begin(), myset.find(3));\n";

	// showing contents:
	output_set("myset", myset);

	output_set("anotherset", anotherset);
	std::cout << "\n";
}

void set_erase(){
	std::cout << GREEN << "Erase test:\n" << DEFAULT;

	std::set<char> myset;
	std::set<char>::iterator it;

	// insert some values:
	for (char i = 'a'; i < 'g'; ++i)
		myset.insert(i);
	std::cout << "set<char> myset;\n"
				 "for (char i = 'a'; i < 'g'; ++i)\n"
				 "\tmyset.insert(i);\n";
	output_set("myset", myset);
	std::cout << "\n";

	it=myset.find('b');
	myset.erase (it);                   // erasing by iterator
	std::cout << "1) erasing by iterator:\n"
				 "\tmyset.erase (myset.find('b'));\n";
	output_set("myset", myset);
	std::cout << "\n";

	myset.erase ('c');                  // erasing by key
	std::cout << "1) erasing by key:\n"
				 "\tmyset.erase ('c');\n";
	output_set("myset", myset);
	std::cout << "\n";

	it=myset.find ('e');
	myset.erase (it, myset.end());    // erasing by range
	std::cout << "1) erasing by range:\n"
				 "\tit=myset.find ('e');\n"
				 "\tmyset.erase (it, myset.end());\n";
	output_set("myset", myset);
	std::cout << "\n";
}

void set_swap() {
	std::cout << GREEN << "Swap test:\n" << DEFAULT;

	std::set<char> foo, bar;

	for (char i = 'x'; i < 'z'; ++i)
		foo.insert(i);

	for (char i = 'a'; i < 'd'; ++i)
		bar.insert(i);

	std::cout << "map<char> foo, bar;\n"
				 "for (char i = 'x'; i < 'z'; ++i)\n"
				 "\tfoo.insert(i);\n"
				 "for (char i = 'a'; i < 'd'; ++i)\n"
				 "\tbar.insert(i);\n";

	foo.swap(bar);

	output_set("foo", foo);
	output_set("bar", bar);
	std::cout << "\n";
}

void set_clear(){
	std::cout << GREEN << "Clear test:\n" << DEFAULT;

	std::set<char> myset;

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);
	std::cout << "set<char> myset;\n"
				 "for (char i = 'a'; i < 'd'; ++i)\n"
				 "\tmyset.insert(i);\n";

	output_set("myset", myset);
	std::cout << "\n";

	myset.clear();
	std::cout << "myset.clear();\n";
	output_set("myset", myset);
	std::cout << "\n";

	for (char i = 'x'; i < 'z'; ++i)
		myset.insert(i);
	std::cout << "for (char i = 'x'; i < 'z'; ++i)\n"
				 "\tmyset.insert(i);\n";
	output_set("myset", myset);

	std::cout << "\n";
}

void set_value_comp(){
	std::cout << GREEN << "Key comp:\n" << DEFAULT;
	std::set<char> myset;

	std::set<char>::key_compare mycomp = myset.key_comp();

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);

	std::cout << "myset contains:\n";

	char highest = *myset.rbegin();     // key value of last element

	std::set<char>::iterator it = myset.begin();
	do {
		std::cout << "\t=> " << *it << '\n';
	} while ( mycomp((*it++), highest) );

	std::cout << '\n';
}

void set_find(){
	std::cout << GREEN << "Find test:\n" << DEFAULT;
	std::set<char> myset;

	std::set<char>::iterator it;

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);

	it = myset.find('b');
	if (it != myset.end())
		myset.erase (it);

	// print content:
	std::cout << "elements in myset:" << '\n';
	std::cout << "a => " << *myset.find('a') << '\n';
	std::cout << "c => " << *myset.find('c') << '\n';
	std::cout << "d => " << *myset.find('d') << '\n';
	std::cout << "\n";
}

void set_count(){
	std::cout << GREEN << "Count test:\n" << DEFAULT;

	std::set<char> myset;
	char c;

	myset.insert('a');
	myset.insert('c');
	myset.insert('f');

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (myset.count(c)>0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
	std::cout << "\n";
}

void set_lower_bound(){
	std::cout << GREEN << "Lower bound test:\n" << DEFAULT;

	std::set<char> myset;
	std::set<char>::iterator itlow, itup;

	for (char i = 'a'; i < 'f'; ++i)
		myset.insert(i);

	itlow=myset.lower_bound ('b');  // itlow points to b
	itup=myset.upper_bound ('d');   // itup points to e (not d!)

	myset.erase(itlow, itup);        // erases [itlow,itup)

	// print content:
	output_set("myset", myset);
	std::cout << "\n";
}

void set_upper_bound(){
	std::cout << GREEN << "Upper bound test:\n" << DEFAULT;
	std::set<char> myset;
	std::set<char>::iterator itlow, itup;

	for (char i = 'a'; i < 'f'; ++i)
		myset.insert(i);

	itlow=myset.lower_bound ('b');  // itlow points to b
	itup=myset.upper_bound ('d');   // itup points to e (not d!)

	myset.erase(itlow, itup);        // erases [itlow,itup)

	// print content:
	output_set("myset", myset);
	std::cout << "\n";
}

void set_equal_range(){
	std::cout << GREEN<< "Equal range test:\n" << DEFAULT;
	std::set<char> myset;

	for (char i = 'a'; i < 'd'; ++i)
		myset.insert(i);

	std::pair<std::set<char>::iterator, std::set<char>::iterator> ret;
	ret = myset.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << "\t=> " << *ret.first<< '\n';

	std::cout << "upper bound points to: ";
	std::cout <<"\t=> " << *ret.second << '\n';
	std::cout << "\n";
}

void set_get_allocator(){
	std::cout << GREEN << "Get allocator test:\n" << DEFAULT;
	int psize;
	std::set<char> myset;
	char* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(std::set<char>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	myset.get_allocator().deallocate(p,5);
	std::cout << "\n";
}

void set_swap_nonmb() {
	std::cout << GREEN << "Swap nonmember test:\n" << DEFAULT;

	std::set<int> foo;
	std::set<int> bar;

	for (int i = 0; i < 2; i++) {
		foo.insert(i);
		foo.insert(i + 5);
		bar.insert(i - 1);
	}

	std::cout << "set<int> foo;\n"
				 "set<int> bar;\n"
				 "for (int i = 0; i < 2; i++) {\n"
				 "\tfoo.insert(i);\n"
				 "\tfoo.insert(i + 5);\n"
				 "\tbar.insert(i - 1);\n"
				 "}";

	std::cout << "foo size = " << foo.size() << std::endl;
	output_set("foo", foo);
	std::cout << "bar size = " << bar.size() << std::endl;
	output_set("bar", bar);

	std::swap(foo, bar);
	std::cout << "\nstd::swap(foo, bar);\n";
	std::cout << "foo size = " << foo.size() << std::endl;
	output_set("foo", foo);
	std::cout << "bar size = " << bar.size() << std::endl;
	output_set("bar", bar);

	std::cout << "\n";
}

// performance

void set_insert_val_performance() {
	std::set<int> s;
	for (int i = 0; i < 100; ++i)
		s.insert(i);
}

void set_insert_hint_performance() {
	std::set<int> s;
	for (int i = 0; i < 100; ++i)
		s.insert(s.end(), i);
}

void set_insert_iterator_performance() {
	std::set<int> s;
	std::set<int> s2;
	for (int i = 0; i < 50; ++i) {
		s2.insert(i);
		s.insert(s2.begin(), s2.end());
	}
}

void set_erase_pos_performance() {
	std::set<int> s;
	for (int i = 0; i < 50; ++i)
		s.insert(i);
	for (int i = 0; i < 50; ++i)
		s.erase(s.begin());
}

void set_erase_val_performance() {
	std::set<int> s;
	for (int i = 0; i < 50; ++i)
		s.insert(i);
	for (int i = 0; i < 50; ++i)
		s.erase(i);
}

void set_erase_iterator_performance() {
	std::set<int> s;
	for (int i = 0; i < 50; ++i)
		s.insert(i);
	std::set<int>::iterator it;
	for (int i = 0; i < 25; ++i) {
		it = s.begin();
		for (size_t i = 0; i < 2; ++i) ++it;
		s.erase(s.begin(), it);
	}
}

void set_find_performance() {
	std::set<int> s;
	for (int i = 0; i < 70; ++i)
		s.insert(i);
	for (int i = 0; i < 90; ++i)
		s.find(i);
}
