#!/bin/bash
if [ $1 == 'ft' ]
then
	sed -i -e 's/std::vector/ft::vector/g' 98tests.cpp
	g++ 98tests.cpp
	time	./a.out
elif [ $1 == 'std' ]
then
	sed -i -e 's/ft::vector/std::vector/g' 98tests.cpp
	g++ 98tests.cpp
	time	./a.out
fi
