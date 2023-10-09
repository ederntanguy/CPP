#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

//#include <iostream>
//#include <string>
//
//#include "Array.hpp"
//
//int main() {
//	std::cout << "int value" << std::endl;
//	Array<int> intValue(10);
//	for (int i = 0; i < 10; ++i) {
//		intValue[i] = i * 10 * i + 5;
//	}
//	for (int i = 0; i < 10; ++i) {
//		std::cout << intValue[i] << std::endl;
//	}
//
//	std::cout << "int length = " << intValue.size() << std::endl;
//
//	try {
//		std::cout << intValue[11] << std::endl;
//	} catch (const std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}
//
//	std::cout << "\nstring value" << std::endl;
//	Array<std::string> *stringValue = new Array<std::string>(5);
//	for (int i = 0; i < 5; ++i) {
//		for (int j = 0; j < i; ++j) {
//			(*stringValue)[i] += "bla";
//		}
//	}
//	for (int i = 0; i < 5; ++i) {
//		std::cout << (*stringValue)[i] << std::endl;
//	}
//	delete stringValue;
//
//	std::cout << "\nempty int value" << std::endl;
//	Array<int> emptyIntValue;
//
//	emptyIntValue = intValue;
//	for (int i = 0; i < 10; ++i) {
//		std::cout << emptyIntValue[i] << std::endl;
//	}
//	return 0;
//}