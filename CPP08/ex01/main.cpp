#include <iostream>

#include "Span.hpp"

int main() {
	Span value(20000);
	for (int i = 0; i < 20000; ++i) {
		value.addNumber(i * i / (1 / i + 1));
	}
	value.addNumber(4);
	std::cout << value.shortestSpan() << std::endl;
	std::cout << value.longestSpan() << std::endl;

	std::cout << "\n//\n" << std::endl;

	Span value2(8);
	value2.addNumber(-4);
	value2.addNumber(-16);
	value2.addNumber(1);
	value2.addNumber(15);
	value2.addNumber(-1);
	value2.addNumber(100);
	std::cout << value2.shortestSpan() << std::endl;
	std::cout << value2.longestSpan() << std::endl;

	std::cout << "\n//\n" << std::endl;

	std::vector<int> vec;
	vec.push_back(-4);
	vec.push_back(1000);
	value2.plageAddNumber(vec.begin(), vec.end());
	value2.addNumber(-1);
	std::cout << value2.shortestSpan() << std::endl;
	std::cout << value2.longestSpan() << std::endl;
}