#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe::PmergeMe(const std::vector<unsigned int> &vecInput) : _vecArray(vecInput) {
	this->_isOdd = this->_vecArray.size() % 2 != 0;
	if (this->_isOdd)
		this->_oddValue = this->_vecArray[this->_vecArray.size() - 1];
}

PmergeMe::PmergeMe(const std::list<unsigned int> &listInput) : _listArray(listInput) {
	this->_isOdd = this->_listArray.size() % 2 != 0;
	if (this->_isOdd)
		this->_oddValue = this->_vecArray[this->_vecArray.size() - 1];
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	this->_listArray = rhs._listArray;
	this->_vecArray = rhs._vecArray;
	return *this;
}


