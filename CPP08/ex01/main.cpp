#include <iostream>

#include "Span.hpp"

int main() {
	Span value(5);
	value.addNumber(1);
	value.addNumber(4);
	value.addNumber(5);
	value.addNumber(9);
	value.addNumber(12);
	value.addNumber(15);
	std::cout << value.shortestSpan() << std::endl;
	std::cout << value.longestSpan() << std::endl;
}