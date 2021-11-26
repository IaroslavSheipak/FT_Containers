// constructing stacks
#include "test_header.hpp"
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // ft::vector
#include <deque>          // std::deque

template<class T, class Container>
void output_stack(std::string name, std::stack<T, Container> s) {
	std::cout << name << " contains:\n";
	if (s.size() == 0)
		std::cout << "\tnothing\n";
	else{
		while(!s.empty()){
			std::cout << s.top() << '\n';
			s.pop();
		}
	}
}

void stack_constructor()
{

	std::cout << GREEN << "Constructor test:\n" << DEFAULT;
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements
	std::cout << "std::deque<int> mydeque (3,100);" << std::endl 
              << "ft::vector<int> myvector (2,200);" << std::endl
              << "std::stack<int> first;" << std::endl
              << "std::stack<int> second (mydeque);" << std::endl;
	std::stack<int> first;                    // empty stack
	std::stack<int> second (mydeque);         // stack initialized to copy of deque


	std::stack<int,ft::vector<int> > third;  // empty stack using vector
	std::stack<int,ft::vector<int> > fourth (myvector);

	output_stack("first", first);
	output_stack("second", second);
	output_stack("third", third);
	output_stack("fourth", fourth);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}


void stack_empty()
{
std::cout << GREEN << "Empty test:\n" << DEFAULT;
  std::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';
}


void stack_size()
{
	std::cout << GREEN << "Size test:\n" << DEFAULT;
  std::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';
}

void stack_top()
{
  std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void stack_push_pop()
{
	std::cout << GREEN << "Push Pop test:\n" << DEFAULT;
  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}


void stack_relational_operators()
{
	std::cout << GREEN << "Relational operators test:\n" << DEFAULT;

  ft::vector<int> first (3,100);
  ft::vector<int> second (2,200);

  std::stack<int,ft::vector<int> > foo(first);  // empty stack using vector
  std::stack<int,ft::vector<int> > bar(second);

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}


