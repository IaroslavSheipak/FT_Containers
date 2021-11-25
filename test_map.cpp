#include "test_header.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const {
	  return lhs < rhs;
  }
};


template<class Key, class T, class Comp, class Alloc>
void output_map(std::string name, std::map<Key, T, Comp, Alloc> &m) {
	std::cout << name << " contains:\n";
	for (typename std::map<Key, T>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << "\t"<< it->first << " => " << it->second << '\n';
	if (m.size() == 0)
		std::cout << "\tnothing\n";
}

void map_iterators(){
	std::cout << GREEN << "Map iterator test:\n" << DEFAULT;

	std::map<int, int> m;
	m[0] = 0;
	m[1] = 0;

	std::map<int, int>::iterator it = m.begin();
	std::map<int, int>::const_iterator it2 = it;
	std::cout << "map<int, int> m;\n"
				 "\tm[0] = 0;\n"
				 "\tm[1] = 0;\n"
				 "std::map<int, int>::iterator it = m.begin();\n"
				 "std::map<int, int>::const_iterator it2 = it;\n";
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

void	map_constructor()
{
	std::cout << GREEN << "Constructor test:\n" << DEFAULT;
	std::cout << "1)map<char,int> first;\n"
	             "\tfirst['a']=10;\n"
	             "\tfirst['b']=30;\n"
	             "\tfirst['c']=50;\n"
	             "\tfirst['d']=70;\n";
	std::map<char,int> first;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	output_map("first", first);
	std::cout << "\n";

	std::map<char,int> second (first.begin(),first.end());
	std::cout << "2)map<char,int> second (first.begin(),first.end());\n";
	output_map("second", second);
	std::cout << "\n";

	std::map<char,int> third (second);
	std::cout << "3)map<char,int> third (second);\n";
	output_map("third", third);
	std::cout << "\n";

	std::map<char,int,classcomp> fourth;                 // class as Compare
	std::cout << "4)map<char,int,classcomp> fourth;\n";

	bool(*fn_pt)(char,char) = fncomp;

	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	std::cout << "\tbool(*fn_pt)(char,char) = fncomp;\n";
	std::cout << "5)map<char,int,bool(*)(char,char)> fifth (fn_pt);\n";
	std::cout << "\n";
}


void map_destructor(){
	std::cout << GREEN << "Destructor test:\n" << DEFAULT;
	std::map<int, SampleClass> m;
	for (int i = 0; i < 5; i++)
		m[i] = SampleClass();
	std::cout << "map<int, SampleClass> m;\n"
				 "\tfor (int i = 0; i < 5; i++)\n"
				 "\t\tm[i] = SampleClass();\n";

	std::cout << "No errors and no leaks -> all is ok\n\n";
}

void map_operator_equals(){
	std::cout << GREEN << "Operator equals test:\n" << DEFAULT;
	std::map<char,int> first;
	std::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;
	std::cout <<    "map<char,int> first;\n"
			        "\tfirst['x']=8;\n"
	                "\tfirst['y']=16;\n"
			        "\tfirst['z']=32;\n"
	                "second = first;\n";
	second = first;                // second now contains 3 ints
	std::cout << "first == second: " << (first == second) << "\n";
	output_map("second", second);
	std::cout << "\n";

	std::cout << "Size of first: " << first.size() << '\n';
	first = std::map<char,int>();  // and first is now empty
	std::cout << "first = map<char,int>();\n";
	output_map("first", first);
	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << "\n\n";
}

void map_begin_end(){
	std::cout << GREEN << "Begin - end test:\n" << DEFAULT;

	std::map<char,int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	std::cout << "map<char,int> mymap;\n"
				 "\tmymap['b'] = 100;\n"
				 "\tmymap['a'] = 200;\n"
				 "\tmymap['c'] = 300;\n";

	// show content:
	std::cout << "for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << "\t" << it->first << " => " << it->second << "\n";
	std::cout << "\n";
}

void map_rbegin_rend(){
	std::cout << GREEN << "Rbegin - rend test:\n" << DEFAULT;

	std::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;
	std::cout << "map<char,int> mymap;\n"
				 "\tmymap['x'] = 100;\n"
				 "\tmymap['y'] = 200;\n"
				 "\tmymap['z'] = 300;\n";

	// show content:
	std::cout << "for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)\n";
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << "\t" << rit->first << " => " << rit->second << "\n";
	std::cout << "\n";
}

void map_empty(){
	std::cout << GREEN << "Empty test:\n" << DEFAULT;

	std::map<char,int> mymap;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::cout << "map<char,int> mymap;\n"
				 "\tmymap['a']=10;\n"
				 "\tmymap['b']=20;\n"
				 "\tmymap['c']=30;\n";

	std::cout << "while is not empty: show begin and then erase begin\n";
	while (!mymap.empty())
	{
		std::cout << "\t" << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
  	}
	std::cout << "\n";
}

void map_size(){
	std::cout << GREEN << "Size test:\n" << DEFAULT;

	std::map<char,int> mymap;
	std::cout << "map<char,int> mymap;\n";
	std::cout << "\tmymap.size() is " << mymap.size() << '\n';
	std::cout << "mymap['a']=101;\n"
				 "mymap['b']=202;\n"
				 "mymap['c']=302;\n";
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "\tmymap.size() is " << mymap.size() << '\n';
	std::cout << "\n";
}

void map_max_size(){
	std::cout << GREEN << "Max size test:\n" << DEFAULT;
	std::map<int,int> mymap;

	std::cout << "If mymap.max_size() > 1000: insert 1000 elements\n";
	if (mymap.max_size() > 1000)
	{
		for (int i = 0; i < 1000; i++)
			mymap[i] = 0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else
		std::cout << "The map could not hold 1000 elements.\n";
	std::cout << "\n";

}

void map_operator_brackets(){
	std::cout << GREEN << "operator brackets test:\n" << DEFAULT;
	std::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n\n";
}

void map_insert(){
	std::cout << GREEN << "Insert test:\n" << DEFAULT;
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;
	// first insert function version (single parameter):
	std::cout << "first insert function version (single parameter):\n";
	mymap.insert ( std::pair<char,int>('a', 100) );
	mymap.insert ( std::pair<char,int>('z', 200) );
	std::cout <<"map<char,int> mymap;\n"
				"\tmymap.insert (pair<char,int>('a', 100));\n"
				"\tmymap.insert (pair<char,int>('z', 200));\n"
				"\tret = mymap.insert (pair<char,int>('z', 500));\n";

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z', 500) );
	if (ret.second==false) {
  		std::cout << "element 'z' already existed";
  		std::cout << " with a value of " << ret.first->second << '\n';
	}
	else
		std::cout << "element 'z' was successfully inserted with a value of " << ret.first->second << '\n';
	output_map("mymap", mymap);

	// second insert function version (with hint position):
	std::cout << "\nsecond insert function version (with hint position):\n";
	it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b', 300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c', 400));  // no max efficiency inserting
	std::cout << "it = mymap.begin();\n"
				 "\tmymap.insert (it, pair<char,int>('b', 300));\n"
				 "\tmymap.insert (it, pair<char,int>('c', 400));\n";
	output_map("mymap", mymap);

	// third insert function version (range insertion):
	std::cout << "\nthird insert function version (range insertion):\n";
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));
	std::cout << "map<char,int> anothermap;\n"
				 "\tanothermap.insert(mymap.begin(), mymap.find('c'));\n";

	// showing contents:
	output_map("mymap", mymap);

	output_map("anothermap", anothermap);
	std::cout << "\n";
}

void map_erase(){
	std::cout << GREEN << "Erase test:\n" << DEFAULT;

	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;
	std::cout << "map<char,int> mymap;\n"
				 "\tmymap['a']=10;\n"
				 "\tmymap['b']=20;\n"
				 "\tmymap['c']=30;\n"
				 "\tmymap['d']=40;\n"
				 "\tmymap['e']=50;\n"
				 "\tmymap['f']=60;\n";
	output_map("mymap", mymap);
	std::cout << "\n";

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	std::cout << "1) erasing by iterator:\n"
				 "\tmymap.erase (mymap.find('b'));\n";
	output_map("mymap", mymap);
	std::cout << "\n";

	mymap.erase ('c');                  // erasing by key
	std::cout << "1) erasing by key:\n"
				 "\tmymap.erase ('c');\n";
	output_map("mymap", mymap);
	std::cout << "\n";

	it=mymap.find ('e');
	mymap.erase (it, mymap.end());    // erasing by range
	std::cout << "1) erasing by range:\n"
				 "\tit=mymap.find ('e');\n"
				 "\tmymap.erase (it, mymap.end());\n";
	output_map("mymap", mymap);
	std::cout << "\n";
}

void map_swap() {
	std::cout << GREEN << "Swap test:\n" << DEFAULT;

	std::map<char,int> foo, bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	std::cout << "map<char,int> foo, bar;\n"
				 "\tfoo['x']=100;\n"
				 "\tfoo['y']=200;\n\n"
				 "\tbar['a']=11;\n"
				 "\tbar['b']=22;\n"
				 "\tbar['c']=33;\n"
				 "foo.swap(bar);\n";

	foo.swap(bar);

	output_map("foo", foo);
	output_map("bar", bar);
	std::cout << "\n";
}


void map_clear(){
	std::cout << GREEN << "Clear test:\n" << DEFAULT;

	std::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;
	std::cout << "map<char,int> mymap;\n"
				 "\tmymap['x']=100;\n"
				 "\tmymap['y']=200;\n"
				 "\tmymap['z']=300;\n";

	output_map("mymap", mymap);
	std::cout << "\n";

	mymap.clear();
	std::cout << "mymap.clear();\n";
	output_map("mymap", mymap);
	std::cout << "\n";

	mymap['a']=1101;
	mymap['b']=2202;
	std::cout << "mymap['a']=1101;\n"
				 "mymap['b']=2202;\n";
	output_map("mymap", mymap);

	std::cout << "\n";
}


void map_key_comp(){
	std::cout << GREEN << "Key comp:\n" << DEFAULT;
	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
  		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
}

void map_value_comp(){
	std::cout << GREEN << "Value comp test:\n" << DEFAULT;
	std::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
  		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	std::cout << "\n";
}


void map_find(){
	std::cout << GREEN << "Find test:\n" << DEFAULT;
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	std::cout << "\n";
}


void map_count(){
	std::cout << GREEN << "Count test:\n" << DEFAULT;

	std::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else 
			std::cout << " is not an element of mymap.\n";
	}
	std::cout << "\n";
}


void map_lower_bound(){
	std::cout << GREEN << "Lower bound test:\n" << DEFAULT;

	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}

void map_upper_bound(){
	std::cout << GREEN << "Upper bound test:\n" << DEFAULT;
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}

void map_equal_range(){
	std::cout << GREEN<< "Equal range test:\n" << DEFAULT;
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "\n";
}


void map_get_allocator(){
	std::cout << GREEN << "Get allocator test:\n" << DEFAULT;
	int psize;
	std::map<char,int> mymap;
	std::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(std::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
	std::cout << "\n";
}

void map_swap_nonmb() {
	std::cout << GREEN << "Swap nonmember test:\n" << DEFAULT;

	std::map<int, int> foo;
	std::map<int, int> bar;

	for (int i = 0; i < 2; i++) {
		foo[i] = i;
		foo[i + 5] = i + 5;
		bar[i - 1] = i - 1;
	}

	std::cout << "map<int, int> foo;\n"
				 "map<int, int> bar;\n"
				 "for (int i = 0; i < 2, i++) {\n"
				 "\tfoo[i] = i;\n"
				 "\tfoo[i + 5] = i + 5;\n"
				 "\tbar[i - 1] = i - 1;\n"
				 "}\n";

	std::cout << "foo size = " << foo.size() << std::endl;
	output_map("foo", foo);
	std::cout << "bar size = " << bar.size() << std::endl;
	output_map("bar", bar);

	std::swap(foo, bar);
	std::cout << "\nstd::swap(foo, bar);\n";
	std::cout << "foo size = " << foo.size() << std::endl;
	output_map("foo", foo);
	std::cout << "bar size = " << bar.size() << std::endl;
	output_map("bar", bar);

	std::cout << "\n";
}

// performance

void map_insert_val_performance() {
	std::map<int, int> m;
	for (int i = 0; i < 100; ++i)
		m.insert(std::make_pair(i, i));
}

void map_insert_hint_performance() {
	std::map<int, int> m;
	for (int i = 0; i < 100; ++i)
		m.insert(m.end(), std::make_pair(i, i));
}

void map_insert_iterator_performance() {
	std::map<int, int> m;
	std::map<int, int> m2;
	for (int i = 0; i < 50; ++i) {
		m2.insert(std::make_pair(i, i));
		m.insert(m2.begin(), m2.end());
	}
}

void map_erase_pos_performance() {
	std::map<int, int> m;
	for (int i = 0; i < 50; ++i)
		m[i] = i;
	for (int i = 0; i < 50; ++i)
		m.erase(m.begin());
}

void map_erase_val_performance() {
	std::map<int, int> m;
	for (int i = 0; i < 50; ++i)
		m[i] = i;
	for (int i = 0; i < 50; ++i)
		m.erase(i);
}

void map_erase_iterator_performance() {
	std::map<int, int> m;
	for (int i = 0; i < 50; ++i)
		m[i] = i;
	std::map<int, int>::iterator it;
	for (int i = 0; i < 25; ++i) {
		it = m.begin();
		for (size_t i = 0; i < 2; ++i) ++it;
		m.erase(m.begin(), it);
	}
}

void map_find_performance() {
	std::map<int, int> m;
	for (int i = 0; i < 70; ++i)
		m[i] = i;
	for (int i = 0; i < 90; ++i)
		m.find(i);
}
