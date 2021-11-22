ifeq ($(USER), suzumaki)	
	TEST_FLAG = yarik
else
	TEST_FLAG = kirill
endif
.PHONY:	ft std all cc

scary_flags = -Wall -Werror -Wextra

NAME = tests

SRCS = test_vector.cpp main.cpp test_map.cpp

all : $(NAME) 

.SUFFIXES: .cpp .o


comp:  
	clang++  -g  -D $(TEST_FLAG) $(SRCS)

all: 
	comp
ft:  
	sed -i -e  's/std::vector/ft::vector/g' main.cpp
	sed -i -e  's/std::vector/ft::vector/g' test_vector.cpp
	sed -i -e  's/std::map/ft::map/g' test_map.cpp
	sed -i -e  's/std::pair/ft::pair/g' test_map.cpp
	make comp
std: 
	sed -i -e  's/ft::vector/std::vector/g' main.cpp
	sed -i -e 's/ft::vector/std::vector/g' test_vector.cpp
	sed -i -e 's/ft::map/std::map/g' test_map.cpp
	sed -i -e 's/ft::pair/std::pair/g' test_map.cpp

	make comp


