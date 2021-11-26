ifeq ($(USER), suzumaki)	
	TEST_FLAG = yarik
else
	TEST_FLAG = kirill
endif
.PHONY:	ft std all cc

scary_flags = -Wall -Werror -Wextra 

NAME = tests

SRCS = test_vector.cpp main.cpp test_map.cpp test_set.cpp test_stack.cpp

all : $(NAME) 

.SUFFIXES: .cpp .o


comp:  
	clang++ $(scary_flags) -g  -D $(TEST_FLAG) $(SRCS)

all: 
	comp
ft:  
	sed -i ''  's/std::vector/ft::vector/g' main.cpp
	sed -i ''  's/std::vector/ft::vector/g' test_vector.cpp
	sed -i ''  's/std::map/ft::map/g' test_map.cpp
	sed -i ''  's/std::pair/ft::pair/g' test_map.cpp
	sed -i ''  's/std::pair/ft::pair/g' test_set.cpp
	sed -i ''  's/std::make_pair/ft::make_pair/g' test_map.cpp
	sed -i ''  's/std::set/ft::set/g' test_set.cpp
	sed -i ''  's/std::stack/ft::stack/g' test_stack.cpp
	make comp
std: 
	sed -i ''  's/ft::vector/std::vector/g' main.cpp
	sed -i '' 's/ft::vector/std::vector/g' test_vector.cpp
	sed -i '' 's/ft::map/std::map/g' test_map.cpp
	sed -i '' 's/ft::pair/std::pair/g' test_map.cpp
	sed -i '' 's/ft::pair/std::pair/g' test_set.cpp
	sed -i '' 's/ft::make_pair/std::make_pair/g' test_map.cpp
	sed -i ''  's/ft::set/std::set/g' test_set.cpp
	sed -i ''  's/ft::stack/std::stack/g' test_stack.cpp

	make comp


