#include <iostream>

#include "easyfind.hpp"

int main() {
	std::list<int> lst1;
	std::vector<int> vec1;
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(4);
	lst1.push_back(3);
	lst1.push_back(8);
	lst1.push_back(7);
	lst1.push_back(6);
	lst1.push_back(5);
	lst1.push_back(9);
	lst1.push_back(10);
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(4);
	vec1.push_back(3);
	vec1.push_back(8);
	vec1.push_back(7);
	vec1.push_back(6);
	vec1.push_back(5);
	vec1.push_back(9);
	vec1.push_back(10);
	std::cout << easyfind(lst1, 13) << std::endl;
	std::cout << easyfind(lst1, 8) << std::endl;
	std::cout << easyfind(vec1, 7) << std::endl;
	std::cout << easyfind(vec1, 70) << std::endl;
}