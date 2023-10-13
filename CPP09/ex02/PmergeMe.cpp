#include "PmergeMe.hpp"

#include <iostream>
#include <iterator>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	(void)rhs;
	return *this;
}

std::vector<std::pair<unsigned long, unsigned long> >
PmergeMe::makePair(std::vector<unsigned long > input) {
	std::vector<std::pair<unsigned long, unsigned long> > returnVec;
	size_t i = 0;
	while (i < input.size() - 1) {
		returnVec.push_back(std::make_pair(input[i], input[i + 1]));
		i+=2;
	}
	return returnVec;
}

std::list<std::pair<unsigned long, unsigned long> >
PmergeMe::makePair(std::list<unsigned long > input) {
	std::list<std::pair<unsigned long, unsigned long> > returnList;
	std::list<unsigned long >::const_iterator it = input.begin();
	std::list<unsigned long >::const_iterator ite = input.end();

	unsigned long tmp1;
	unsigned long tmp2;

	while (it != ite) {
		tmp1 = *it;
		++it;
		tmp2 = *it;
		returnList.push_back(std::make_pair(tmp1, tmp2));
		++it;
	}
	return returnList;
}