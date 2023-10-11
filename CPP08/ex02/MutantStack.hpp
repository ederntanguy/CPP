#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack<T>();
	MutantStack<T>(const MutantStack<T> &src);
	~MutantStack<T>();

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	MutantStack &operator=(const MutantStack<T> &rhs);
};


template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs) {
	this->c = rhs.c;
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {
	*this = src;
}

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

#endif //CPP08_MUTANTSTACK_HPP
