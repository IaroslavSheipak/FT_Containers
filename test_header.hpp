#pragma once
#ifdef yarik
#include "../ft_containers/vector/Vector.hpp"
//#include "../ft_containers/iterator/iterator.hpp"
#include "../ft_containers/map/RBTree.hpp"
#include "../ft_containers/map/Map.hpp"
#include "../ft_containers/set/Set.hpp"
#include "../ft_containers/stack/Stack.hpp"
#endif
#ifdef kirill
#include "../ft_containers/stack/stack.hpp"
#include "../ft_containers/map/map.hpp"
#include "../ft_containers/set/set.hpp"
#endif
#include "SampleClass.hpp"
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <set>

# define B_CYAN "\x1b[46;1m"
# define B_RED  "\x1b[41;1m"
# define YELLOW "\x1b[33;1m"
# define RED    "\x1b[31;1m"
# define GREEN  "\x1b[32;1m"
# define BLUE    "\x1b[34;1m"
# define DEFAULT "\x1b[m"



// map

void	map_iterators();
void	map_constructor();
void	map_destructor();
void	map_operator_equals();
void	map_begin_end();
void	map_rbegin_rend();
void	map_empty();
void	map_size();
void	map_max_size();
void	map_operator_brackets();
void	map_insert();
void	map_erase();
void	map_swap();
void	map_clear();
void	map_swap_nonmb();

// performance

void map_insert_val_performance();
void map_insert_hint_performance();
void map_insert_iterator_performance();
void map_erase_pos_performance();
void map_erase_val_performance();
void map_erase_iterator_performance();
void map_find_performance();

// vector

void	vector_iterators();
void	vector_constructor();
void	vector_operator_equal();
void	vector_destructor();
void	vector_begin_end();
void	vector_rbegin_rend();
void	vector_size();
void	vector_max_size_capacity();
void	vector_resize();
void	vector_empty();
void	vector_reserve();
void	vector_operator_brackets();
void	vector_at();
void	vector_front();
void	vector_back();
void	vector_assign();
void	vector_push_back();
void	vector_pop_back();
void	vector_insert();
void	vector_erase();
void	vector_swap();
void	vector_clear();
void	vector_get_allocator();
void	vector_relational_operators();
void	vector_swap_nonmb();

// performance

void	vector_push_back_performance();
void	vector_insert_val_performance();
void	vector_insert_fill_performance();
void	vector_insert_iterator_performance();
void	vector_erase_pos_performance();
void	vector_erase_iterator_performance();
void	vector_reserve_performance();
void	vector_resize_performance();
void	vector_assign_val_performance();
void	vector_assign_iterator_performance();

// set

void	set_iterators();
void	set_constructor();
void	set_destructor();
void	set_operator_equals();
void	set_begin_end();
void	set_rbegin_rend();
void	set_empty();
void	set_size();
void	set_max_size();
void	set_insert();
void	set_erase();
void	set_swap();
void	set_clear();
void	set_swap_nonmb();

// performance

void set_insert_val_performance();
void set_insert_hint_performance();
void set_insert_iterator_performance();
void set_erase_pos_performance();
void set_erase_val_performance();
void set_erase_iterator_performance();
void set_find_performance();

//stack

void stack_constructor();
void stack_empty();
void stack_size();
void stack_top();
void stack_push_pop();
void stack_relational_operators();
