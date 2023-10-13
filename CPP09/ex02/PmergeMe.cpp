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
PmergeMe::makePair(std::vector<unsigned long > input) const {
	std::vector<std::pair<unsigned long, unsigned long> > returnVec;
	size_t i = 0;
	while (i < input.size() - 1) {
		returnVec.push_back(std::make_pair(input[i], input[i + 1]));
		i+=2;
	}
	return returnVec;
}

std::list<std::pair<unsigned long, unsigned long> >
PmergeMe::makePair(std::list<unsigned long > input) const {
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

void
PmergeMe::sortPair(std::vector<std::pair<unsigned long, unsigned long> > &values) const {
	size_t i = 0;
	unsigned long tmp;
	while (i < values.size()) {
		if (values[i].first > values[i].second) {
			tmp = values[i].first;
			values[i].first = values[i].second;
			values[i].second = tmp;
		}
		i++;
	}
}

void
PmergeMe::sortPair(std::list<std::pair<unsigned long, unsigned long> > &values) const {
	std::list<std::pair<unsigned long, unsigned long> >::iterator it;
	std::list<std::pair<unsigned long, unsigned long> >::iterator ite = values.end();

	unsigned long tmp;
	for (it = values.begin(); it != ite; ++it) {
		if ((*it).first > (*it).second) {
			tmp = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tmp;
		}
	}
}
