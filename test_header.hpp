#pragma once
#ifdef yarik
#include "../ft_containers/vector/Vector.hpp"
#include "../ft_containers/iterator/iterator.hpp"
#include "../ft_containers/map/RBTree.hpp"
#endif
#ifdef kirill
#include "../ft_containers/stack/stack.hpp"
#endif
#include "SampleClass.hpp"
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>

# define B_CYAN "\x1b[46;1m" <<
# define B_RED  "\x1b[41;1m" <<
# define YELLOW "\x1b[33;1m" <<
# define RED    "\x1b[31;1m" <<
# define GREEN  "\x1b[32;1m" <<
# define DEFAULT << "\x1b[m"

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

void	vector_iterators();
void	vector_constructor();
void	vector_destructor();
void	vector_begin_end();
void	vector_rbegin_rend();
void	vector_size();
void	vector_max_size_capacity();
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
void	vector_swap();
