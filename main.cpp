
#ifdef yarik
#include "../ft_containers/vector/Vector.hpp"
#include "../ft_containers/iterator/iterator.hpp"
#include "../ft_containers/map/RBTree.hpp"
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


//void test_map() {
//
//	int *a;
//	RBTree<int> tree;
//	std::allocator<int> allocator;
//
//	a = allocator.allocate(50, a);
//	for (int i = 0; i < 50; i++)
//	{
//		allocator.construct(a + i, i);
//		tree.insert((a + i));
//	}
//}

int main()
{
	ft::vector<int>::iterator iter;
	ft::vector<int>::const_iterator const_iter;

	const_iter = iter;
	//iter = const_iter;
	
	//test_map();
	//test_vector();	
	return (0);
}
