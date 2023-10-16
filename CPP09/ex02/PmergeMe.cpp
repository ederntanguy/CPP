#include "PmergeMe.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>

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
PmergeMe::sortInPairs(std::vector<std::pair<unsigned long, unsigned long> > &values) const {
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
PmergeMe::sortInPairs(std::list<std::pair<unsigned long, unsigned long> > &values) const {
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

void PmergeMe::insertPairs(std::pair<unsigned long, unsigned long> element,
						   std::vector<std::pair<unsigned long, unsigned long> > &values,
						   int pos) const {
	if (pos < 0)
		values[0] = element;
	else if (element.second > values[pos].second) {
		values[pos + 1] = element;
	} else {
		values[pos + 1] = values[pos];
		insertPairs(element, values, pos - 1);
	}
}

void PmergeMe::pairsInsertionSort(
		std::vector<std::pair<unsigned long, unsigned long> > &values,
		int pos) const {
	if (pos < 1)
		return;
	pairsInsertionSort(values, pos - 1);
	insertPairs(values[pos], values, pos - 1);
}

void PmergeMe::insertPairs(std::pair<unsigned long, unsigned long> element,
						   std::list<std::pair<unsigned long, unsigned long> > &values,
						   int pos) const {
	std::list<std::pair<unsigned long, unsigned long> >::iterator itStart = values.begin();
	std::list<std::pair<unsigned long, unsigned long> >::iterator itPos = values.begin();
	std::advance(itPos, pos);
	std::list<std::pair<unsigned long, unsigned long> >::iterator itPosPOne = values.begin();
	std::advance(itPosPOne, pos + 1);
	if (pos < 0)
		*itStart = element;
	else if (element.second > (*itPos).second) {
		(*itPosPOne) = element;
	} else {
		(*itPosPOne) = (*itPos);
		insertPairs(element, values, pos - 1);
	}
}

void PmergeMe::pairsInsertionSort(
		std::list<std::pair<unsigned long, unsigned long> > &values,
		int pos) const {
	if (pos < 1)
		return;
	pairsInsertionSort(values, pos - 1);
	std::list<std::pair<unsigned long, unsigned long> >::iterator it = values.begin();
	std::advance(it, pos);
	insertPairs(*it, values, pos - 1);
}

void showVec(std::vector<unsigned long> &vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
		if (i % 10 == 0 && i != 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<unsigned long> PmergeMe::creatSortedArray(
		std::vector<std::pair<unsigned long, unsigned long> > &values,
		unsigned long straggler, bool isOdd) {
	std::vector<unsigned long> s;
	std::vector<unsigned long> pend;
	// creat s
	for (size_t i = 0; i < values.size(); ++i) {
		s.push_back(values[i].second);
		pend.push_back(values[i].first);
	}

	std::vector<unsigned long>::iterator it = s.begin();
	s.insert(it, *(pend.begin()));

	// time to had pend in s
	size_t iterator = 1;
	while (iterator < pend.size()) {
		it = std::lower_bound(s.begin(), s.end(), pend[iterator]);
		s.insert(it, pend[iterator]);
		iterator++;
	}
	if (isOdd) {
		it = std::lower_bound(s.begin(), s.end(), straggler);
		s.insert(it, straggler);
	}
	return s;
}

std::list<unsigned long> PmergeMe::creatSortedArray(
		std::list<std::pair<unsigned long, unsigned long> > &values,
		unsigned long straggler, bool isOdd) {

	std::list<unsigned long> s;
	std::list<unsigned long> pend;

	std::list<std::pair<unsigned long, unsigned long> >::iterator itV;
	std::list<std::pair<unsigned long, unsigned long> >::iterator itVe = values.end();

	for (itV = values.begin(); itV != itVe; ++itV) {
		s.push_back((*itV).second);
		pend.push_back((*itV).first);
	}
	s.insert(s.begin(), *(pend.begin()));

//	std::list<unsigned long>::iterator itV2;
//	std::list<unsigned long>::iterator itVe2 = pend.end();
//	for (itV2 = pend.begin(); itV2 != itVe2; ++itV2) {
//		std::cout << *itV2 << " ";
//	}
//	std::list<unsigned long>::iterator itV3;
//	std::list<unsigned long>::iterator itVe3 = s.end();
//	for (itV3 = s.begin(); itV3 != itVe3; ++itV3) {
//		std::cout << *itV3 << " ";
//	}
	// time to had pend in s

	std::list<size_t> indexsequence;
	indexsequence.push_back(1);

	std::list<size_t>::iterator itPendB = pend.begin();
	std::list<size_t>::iterator itPendE = pend.end();
	std::list<size_t>::iterator itS;

	++itPendB;
	for (std::list<size_t>::iterator itPendBP1 = itPendB; itPendBP1 != itPendE ; ++itPendBP1)
	{
		itS = std::lower_bound(s.begin(), s.end(), *itPendBP1);
		s.insert(itS, *itPendBP1);
	}
	if (isOdd) {
		itS = std::lower_bound(s.begin(), s.end(), straggler);
		s.insert(itS, straggler);
	}
	return s;
}






