#include "test_header.hpp"

//void time(clock_t end, clock_t start){
//
//	std::cout << BLUE << end - start << std::endl << DEFAULT;
//}

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

void speed_test(std::string name, void (&func)()) {
	clock_t start, end;
	start = clock();
	func();
	end = clock();
	std::cout << BLUE << name << " " << end - start << std::endl << DEFAULT;
//	time(end, start);
	std::cout << std::endl;
}

void run_func(std::string name, void (&func)()) {
	(void) name;
	func();
}


void test_vector(void (dec)(std::string name, void (&func)())) {
	std::cout << YELLOW << "VECTOR TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;

	dec("vector_iterators", vector_iterators);
	dec("vector_constructor", vector_constructor);
	dec("vector_destructor", vector_destructor);
	dec("vector_operator_equal", vector_operator_equal);
	dec("vector_begin_end", vector_begin_end);
	dec("vector_rbegin_rend", vector_rbegin_rend);
	dec("vector_size", vector_size);
	dec("vector_max_size_capacity", vector_max_size_capacity);
	dec("vector_resize", vector_resize);
	dec("vector_empty", vector_empty);
	dec("vector_reserve", vector_reserve);
	dec("vector_operator_brackets", vector_operator_brackets);
	dec("vector_at", vector_at);
	dec("vector_front", vector_front);
	dec("vector_back", vector_back);
	dec("vector_assign", vector_assign);
	dec("vector_push_back", vector_push_back);
	dec("vector_pop_back", vector_pop_back);
	dec("vector_insert", vector_insert);
	dec("vector_erase", vector_erase);
	dec("vector_swap", vector_swap);
	dec("vector_clear", vector_clear);
	dec("vector_get_allocator", vector_get_allocator);
	dec("vector_relational_operators", vector_relational_operators);
	dec("vector_swap_nonmb", vector_swap_nonmb);

	std::cout << YELLOW << "/////////\n" << DEFAULT;
}


void test_map(void (dec)(std::string name, void (&func)())) {

	std::cout << YELLOW << "MAP TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;

	dec("map_iterators", map_iterators);
	dec("map_constructor", map_constructor);
	dec("map_destructor", map_destructor);
	dec("map_operator_equals", map_operator_equals);
	dec("map_begin_end", map_begin_end);
	dec("map_rbegin_rend", map_rbegin_rend);
	dec("map_empty", map_empty);
	dec("map_size", map_size);
	dec("map_max_size", map_max_size);
	dec("map_operator_brackets", map_operator_brackets);
	dec("map_insert", map_insert);
	dec("map_erase", map_erase);
	dec("map_swap", map_swap);
	dec("map_clear", map_clear);
	dec("map_swap_nonmb", map_swap_nonmb);

	std::cout << YELLOW << "/////////\n" << DEFAULT;
}

void test_map_performance(void (dec)(std::string name, void (&func)())) {
	std::cout << YELLOW << "MAP PERFORMANCE TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;

	dec("map_insert_val_performance", map_insert_val_performance);
	dec("map_insert_hint_performance", map_insert_hint_performance);
	dec("map_insert_iterator_performance", map_insert_iterator_performance);
	dec("map_erase_pos_performance", map_erase_pos_performance);
	dec("map_erase_val_performance", map_erase_val_performance);
	dec("map_erase_iterator_performance", map_erase_iterator_performance);
	dec("map_find_performance", map_find_performance);

	std::cout << YELLOW << "/////////\n" << DEFAULT;
}

void test_vector_performance(void (dec)(std::string name, void (&func)())) {
	std::cout << YELLOW << "VECTOR PERFORMANCE TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;

	dec("vector_push_back_performance", vector_push_back_performance);
	dec("vector_insert_val_performance", vector_insert_val_performance);
	dec("vector_insert_fill_performance", vector_insert_fill_performance);
	dec("vector_insert_iterator_performance", vector_insert_iterator_performance);
	dec("vector_erase_pos_performance", vector_erase_pos_performance);
	dec("vector_erase_iterator_performance", vector_erase_iterator_performance);
	dec("vector_reserve_performance", vector_reserve_performance);
	dec("vector_resize_performance", vector_resize_performance);
	dec("vector_assign_val_performance", vector_assign_val_performance);
	dec("vector_assign_iterator_performance", vector_assign_iterator_performance);

	std::cout << YELLOW << "/////////\n" << DEFAULT;
}

void test_set(void (dec)(std::string name, void (&func)())) {

	std::cout << YELLOW << "SET TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;

	dec("set_iterators", set_iterators);
	dec("set_constructor", set_constructor);
	dec("set_destructor", set_destructor);
	dec("set_operator_equals",set_operator_equals);
	dec("set_begin_end", set_begin_end);
	dec("set_rbegin_rend", set_rbegin_rend);
	dec("set_empty", set_empty);
	dec("set_size", set_size);
	dec("set_max_size", set_max_size);
	dec("set_insert", set_insert);
	dec("set_erase", set_erase);
	dec("set_swap", set_swap);
	dec("set_clear", set_clear);
	dec("set_swap_nonmb", set_swap_nonmb);

	std::cout << YELLOW << "/////////\n" << DEFAULT;
}

void test_set_performance(void (dec)(std::string name, void (&func)())) {
	std::cout << YELLOW << "SET PERFORMANCE TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;

	dec("set_insert_val_performance", set_insert_val_performance);
	dec("set_insert_hint_performance", set_insert_hint_performance);
	dec("set_insert_iterator_performance", set_insert_iterator_performance);
	dec("set_erase_pos_performance", set_erase_pos_performance);
	dec("set_erase_val_performance", set_erase_val_performance);
	dec("set_erase_iterator_performance", set_erase_iterator_performance);
	dec("set_find_performance", set_find_performance);

	std::cout << YELLOW << "/////////\n" << DEFAULT;
}

void  test_stack(){
	std::cout << YELLOW << "STACK TESTS:\n" << DEFAULT;
	std::cout << YELLOW << "\\\\\\\\\\\\\\\\\\\n\n" << DEFAULT;
	stack_constructor();
	stack_empty();
	stack_size();
	stack_top();
	stack_push_pop();
	stack_relational_operators();
	std::cout << YELLOW << "/////////\n" << DEFAULT;
}

int main()
{
	//test_map(run_func); // default test
	//test_map(speed_test); // speed test
	//test_map_performance(speed_test); // performance

	//test_vector(run_func); // default test
	//test_vector(speed_test); // speed test
	//test_vector_performance(speed_test); //performance

	//test_set(run_func); // default test
	//test_map(speed_test); // speed test
	//test_set_performance(speed_test); // performance
	test_stack();
	return (0);
}
