ifeq ($(USER), suzumaki)	
	TEST_FLAG = yarik
else
	TEST_FLAG = kirill
endif

all:
	clang++ -g -D $(TEST_FLAG) vector_tests.cpp
