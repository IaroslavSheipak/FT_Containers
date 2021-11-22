#include "test_header.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void	map_constructor()
{
	std::cout << "Constructor test:\n";
	std::cout << "1)map<char,int> first;\n"
	             "\tfirst['a']=10;\n"
	             "\tfirst['b']=30;\n"
	             "\tfirst['c']=50;\n"
	             "\tfirst['d']=70;\n";
	ft::map<char,int> first;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	ft::map<char,int> second (first.begin(),first.end());
	std::cout << "2)map<char,int> second (first.begin(),first.end());\n";
	std::cout << "\tfirst == second: " << (first == second) << std::endl;

	ft::map<char,int> third (second);
	std::cout << "3)map<char,int> third (second);\n";
	std::cout << "\tsecond == third: " << (second == third) << std::endl;

	ft::map<char,int,classcomp> fourth;                 // class as Compare
	std::cout << "4)map<char,int,classcomp> fourth;\n";

	bool(*fn_pt)(char,char) = fncomp;

	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	std::cout << "5)map<char,int,bool(*)(char,char)> fifth (fn_pt);\n";
	std::cout << "\n\n";
}


void map_destructor(){
	std::cout << "Destructor test:\n";
	ft::map<int, SampleClass> m;
	for (int i = 0; i < 5; i++)
		m[i] = SampleClass();
	std::cout << "No errors and no leaks -> all is ok\n\n";
}

void map_operator_equals(){
	std::cout << "Operator equals test:\n";
	ft::map<char,int> first;
	ft::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;
	std::cout <<    "ft::map<char,int> first;\n"
			        "\tfirst['x']=8;\n"
	                "\tfirst['y']=16;\n"
			        "\tfirst['z']=32;\n"
	                "second=first;\n";
	second=first;                // second now contains 3 ints
	std::cout << "first == second: " << (first == second) << "\n\n";

	std::cout << "Size of first: " << first.size() << '\n';
	first=ft::map<char,int>();  // and first is now empty
	std::cout << "first=ft::map<char,int>();\n";
	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << "\n\n";
}

void map_begin_end(){
	std::cout << "Begin - end test:\n";

	ft::map<char,int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << "\n\n";
}

void map_rbegin_rend(){
	std::cout << "Rbegin - rend test:\n";

	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << "\n\n";
}

void map_empty(){
	std::cout << "Empty test:\n";

	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
  	}
	std::cout << "\n";
}

void map_size(){
	std::cout << "Size test:\n";

	ft::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	std::cout << "\n";
}

void map_max_size(){
	std::cout << "Max size test:\n";
	int i;
	ft::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n\n";
}

void map_operator_brackets(){
	std::cout << "operator brackets test:\n";
	ft::map<char,std::string> mymap;

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
	std::cout << "Insert test:\n";
	ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
  		std::cout << "element 'z' already existed";
  		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}

void map_erase(){
	std::cout << "Erase test:\n";

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}

void map_swap(){
	std::cout << "Swap test:\n";

	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}


void map_clear(){
	std::cout << "Clear test:\n";

	ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}


void map_key_comp(){
	std::cout << "Key comp:\n";
	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
  		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
}

void map_value_comp(){
	std::cout << "Value comp test:\n";
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
  		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	std::cout << "\n";
}


void map_find(){
	std::cout << "Find test:\n";
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

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
	std::cout << "Count test:\n";

	ft::map<char,int> mymap;
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
	std::cout << "Lower bound test:\n";

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}

void map_upper_bound(){
	std::cout << "Upper bound test:\n";
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "\n";
}

void map_equal_range(){
	std::cout << "Equal range test:\n";
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << "\n";
}


void map_get_allocator(){
	std::cout << "Get allocator test:\n";
	int psize;
	ft::map<char,int> mymap;
	ft::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
	std::cout << "\n";
}
