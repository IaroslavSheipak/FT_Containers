#include "test_header.hpp"

void time(clock_t end, clock_t start){
	
	std::cout << GREEN << end - start << std::endl << DEFAULT;
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

void test_vector() {
	std::cout << YELLOW << "VECTOR TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;
	vector_iterators();
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
	std::cout << YELLOW << "/////////\n" << DEFAULT;
}


void test_map() {

	std::cout << YELLOW << "MAP TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;
	map_iterators();
	map_constructor();
	map_destructor();
	map_operator_equals();
	map_begin_end();
	map_rbegin_rend();
	map_empty();
	map_size();
	map_max_size();
	map_operator_brackets();
	map_insert();
	map_erase();
	map_swap();
	map_clear();
	std::cout << YELLOW << "/////////\n" << DEFAULT;
}


int main()
{
	
	//RBTree<int> tree;
//	ft::map<int, int> map;
	//int *num = new int(5);
//	int num = 5;
//	map[num] = 6;
//	ft::map<int, int>::iterator iter = map.find(num);
//	map.insert(ft::pair<int, int>(5, 5));
	//map.erase(iter);
//	map.clear();

	test_map();
	//test_vector();
	return (0);
}
