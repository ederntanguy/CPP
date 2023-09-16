#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
	std::cout << "int value" << std::endl;
	Array<int> intValue(10);
	for (int i = 0; i < 10; ++i) {
		intValue[i] = i * 10 * i + 5;
	}
	for (int i = 0; i < 10; ++i) {
		std::cout << intValue[i] << std::endl;
	}

	std::cout << "\nstring value" << std::endl;
	Array<std::string> *stringValue = new Array<std::string>(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < i; ++j) {
			(*stringValue)[i] += "bla";
		}
	}
	for (int i = 0; i < 5; ++i) {
		std::cout << (*stringValue)[i] << std::endl;
	}
	delete stringValue;

	std::cout << "\nempty int value" << std::endl;
	Array<int> emptyIntValue;

	emptyIntValue = intValue;
	for (int i = 0; i < 10; ++i) {
		std::cout << emptyIntValue[i] << std::endl;
	}
	return 0;
}