#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack<T>();
	MutantStack<T>(const MutantStack<T> &src);
	~MutantStack<T>();

	MutantStack &operator=(const MutantStack<T> &rhs);

	class iterator {
	public:
		iterator();
		~iterator();

		iterator &operator++();
		iterator operator++(int);
		iterator &operator--();
		iterator operator--(int);
		bool operator!=(const iterator &rhs);
		bool operator==(const iterator &rhs);
		iterator &operator=(const iterator &rhs);

	private:
		T   *_pointer;
	} ;

	iterator begin();
	iterator end();
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return &(this->c[this->size() - 1]);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return &(this->c[0]);
}

template<typename T>
MutantStack<T>::iterator::iterator() {}

template<typename T>
MutantStack<T>::iterator::~iterator() {}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const MutantStack::iterator &rhs) {
	this->_pointer = rhs._pointer;
	return *this;
}

template<typename T>
bool MutantStack<T>::iterator::operator==(const MutantStack::iterator &rhs) {
	if (this->_pointer != rhs._pointer)
		return true;
	return false;
}

template<typename T>
bool MutantStack<T>::iterator::operator!=(const MutantStack::iterator &rhs) {
	if (this->_pointer == rhs._pointer)
		return true;
	return false;
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int) {
	MutantStack<T>::iterator &tmp = *this;
	MutantStack<T>::iterator::operator--();
	return tmp;
}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--() {
	this->_pointer--;
	return *this;
}


template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int) {
	MutantStack<T>::iterator &tmp = *this;
	MutantStack<T>::iterator::operator++();
	return tmp;
}

template<typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++() {
	this->_pointer++;
	return *this;
}

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
