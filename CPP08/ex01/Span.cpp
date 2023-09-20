#include "Span.hpp"

Span::Span() {
	std::vector<int> v2(0);
	this->_v1 = v2;
}

Span::Span(int N) {
	std::vector<int> v2(N);
	this->_v1 = v2;
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {}

void Span::addNumber(int value) {

}

int Span::shortestSpan() const {
	return 0;
}

int Span::longestSpan() const {
	return 0;
}

Span &Span::operator=(const Span &rhs) {
	return <#initializer#>;
}
