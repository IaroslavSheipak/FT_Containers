ifeq ($(USER), suzumaki)	
	TEST_FLAG = yarik
else
	TEST_FLAG = kirill
endif
.PHONY:	ft std all cc

comp:  
	clang++ -g   -D $(TEST_FLAG) main.cpp

all: 
	comp
ft:  
	sed -i -e 's/std::vector/ft::vector/g' main.cpp
	make comp
std: 
	sed -i -e 's/ft::vector/std::vector/g' main.cpp
	make comp


