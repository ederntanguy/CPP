#include <iostream>

#include "iter.hpp"

int main( void ) {
	std::cout << "classic int" << std::endl;
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
	int *intTab[] = { &a, &b, &c, &d, &e, &f };
	iter(intTab, 6, decrementVal<int>);
	for (int i = 0; i < 6; ++i) {
		std::cout << (*intTab)[i] << std::endl;
	}

	std::cout << "\nclassic char" << std::endl;
	char aa = 'c', bb = 'g', cc = 'e', dd = 'r';
	char *charTab[] = { &aa, &bb, &cc, &dd};
	iter(charTab, 4, decrementVal<char>);
	for (int i = 0; i < 4; ++i) {
		std::cout << (*charTab)[i] << std::endl;
	}

	std::cout << "\nclassic float" << std::endl;
	float o = 1.1f, p = 2.2f, q = -47.5678f, r = 7988.798f, s = 0.0f;
	float *boolTab[] = {&o, &p, &q, &r, &s};
	iter(boolTab, 5, decrementVal<float>);
	for (int i = 0; i < 5; ++i) {
		std::cout << (*boolTab)[i] << std::endl;
	}

	std::cout << "\n int 0 or 1" << std::endl;
	a = 0, b = 0, c = 0, d = 0, e = 1, f = 0;
	int *intZeroTab[] = { &a, &b, &c, &d, &e, &f };
	iter(intZeroTab, 6, doSomething<int>);
	for (int i = 0; i < 6; ++i) {
		std::cout << (*intTab)[i] << std::endl;
	}

//	for (int i = 0; i < 3; ++i) {
//		std::cout << charTab[i] << std::endl;
//	}

//	for (int i = 0; i < 4; ++i) {
//		std::cout << boolTab[i] << std::endl;
//	}


	return 0;
}