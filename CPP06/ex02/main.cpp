/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:37:26 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/05 15:37:26 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include <cstdlib>

class Base {
public:
	inline virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void) {
	Base *value;
	srand(time(0));
	int i = rand() % 3;
	if (i == 0)
		value = new A;
	else if (i == 1)
		value = new B;
	else
		value = new C;
	std::cout << i << std::endl;
	return value;
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "it's a A pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "it's a B pointer" << std::endl;
	else
		std::cout << "it's a C pointer" << std::endl;
}

void identify(Base& p) {
	try {
		dynamic_cast<A &>(p);
		std::cout << "it's a A reference" << std::endl;
		return;
	}
	catch (...) {}
	try {
		dynamic_cast<B &>(p);
		std::cout << "it's a B reference" << std::endl;
		return;
	}
	catch (...) {}
	std::cout << "it's a C reference" << std::endl;
}

int main() {
	Base *value = generate();
	identify(value);
	identify(*value);
	return 0;
}