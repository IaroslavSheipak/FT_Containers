#!/bin/bash
if [ $1 == 'ft' ]
then
	sed -i -e 's/std::vector/ft::vector/g' 98tests.cpp
	sed -i -e 's/std::vector/ft::vector/g' test_reverse_iterator.cpp
	sed -i -e 's/std::reverse_iterator/ft::reverse_iterator/g' test_reverse_iterator.cpp
	clang++ -g  98tests.cpp -o 98tests
	clang++ -g test_reverse_iterator.cpp -o RevIt
	time	./98tests
	time	./RevIt
elif [ $1 == 'std' ]
then
	sed -i -e 's/ft::vector/std::vector/g' 98tests.cpp
	sed -i -e 's/ft::vector/std::vector/g' test_reverse_iterator.cpp
	sed -i -e 's/ft::reverse_iterator/std::reverse_iterator/g' test_reverse_iterator.cpp
	clang++ -g  98tests.cpp -o 98tests
	clang++ -g test_reverse_iterator.cpp -o RevIt
	time	./98tests
	time	./RevIt
fi
