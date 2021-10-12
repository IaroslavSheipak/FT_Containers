#include "vector/Vector.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> a(5);
	//a[0] = 42;
	
	std::sort(++a.begin(), a.end());
	std::cout << a[0] << std::endl;
	return (0);
}
