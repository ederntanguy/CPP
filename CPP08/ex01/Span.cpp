#include "Span.hpp"

#include <iostream>
#include <cstdlib>

Span::Span() : _nbAdd(0) {
	std::vector<int> v2(0);
	this->_v1 = v2;
}

Span::Span(int N) : _nbAdd(0) {
	std::vector<int> v2(N);
	this->_v1 = v2;
}

Span::Span(const Span &src) {
	std::vector<int> v2(src._v1.size());
	this->_v1 = v2;
	*this = src;
}

Span::~Span() {}

void Span::addNumber(int value) {
	try {
		if (static_cast<long unsigned int>(this->_nbAdd) == this->_v1.size())
			throw ToManyAddException();
		this->_v1[this->_nbAdd] = value;
		this->_nbAdd++;
	}
	catch (ToManyAddException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
}

int Span::shortestSpan() const {
	try {
		if (this->_nbAdd < 2)
			throw NoNumberEnoughForSearchException();
		int min = abs(this->_v1[0] - this->_v1[1]);
		int tmpMin;
		for (int i = 0; i < this->_nbAdd; ++i) {
			for (int j = 0; j < this->_nbAdd; ++j) {
				if (j != i && abs(this->_v1[i] - this->_v1[j]) < min)
					min = abs(this->_v1[i] - this->_v1[j]);
			}
			if (i == 0)
				tmpMin = min;
			else if (min < tmpMin)
				tmpMin = min;
		}
		return tmpMin;
	}
	catch (NoNumberEnoughForSearchException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
		return 0;
	}
}

int Span::longestSpan() const {
	try {
		if (this->_nbAdd < 2)
			throw NoNumberEnoughForSearchException();
		int min = this->_v1[0];
		int max = this->_v1[1];
		for (int i = 0; i < this->_nbAdd; ++i) {
			if (min > this->_v1[i])
				min = this->_v1[i];
			if (max < this->_v1[i])
				max = this->_v1[i];
		}
		return max - min;
	}
	catch (NoNumberEnoughForSearchException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
		return 0;
	}
}

Span &Span::operator=(const Span &rhs) {
	for (int i = 0; i < static_cast<int>(rhs._v1.size()); ++i)
	{
		this->_v1[i] = rhs._v1[i];
	}
	this->_nbAdd = rhs._nbAdd;
	return *this;
}

void Span::plageAddNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
	while (begin != end) {
		addNumber(*begin);
		begin++;
	}
}
