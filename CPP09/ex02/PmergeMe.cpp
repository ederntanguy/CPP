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

size_t jacobsthal(size_t val) {
	if (val == 0)
		return 0;
	if (val == 1)
		return 1;
	return (jacobsthal(val - 1) + 2 * jacobsthal(val - 2));
}

std::vector<unsigned long>
        creatJacobInsertionSequence(const std::vector<unsigned long> &pend) {
	size_t pendLen = pend.size() - 1;
	std::vector<size_t> sequence;
	size_t index = 3; // first one that matteres

	while (jacobsthal(index) < pendLen) {
		sequence.push_back(jacobsthal(index));
		index++;
	}
	return sequence;
}

std::list<unsigned long>
		creatJacobInsertionSequence(const std::list<unsigned long> &pend) {
	size_t pendLen = pend.size() - 1;
	std::list<size_t> sequence;
	size_t index = 3; // first one that matteres because we already insert the first one

	while (jacobsthal(index) < pendLen) {
		sequence.push_back(jacobsthal(index));
		index++;
	}
	return sequence;
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
		std::cout << vec[i] << std::endl;
	}
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
	size_t iterator = 0;
	std::vector<size_t> indexsequence;
	indexsequence.push_back(1);
	int where = 0;
	unsigned long valToHade;

	std::vector<size_t> sequence = creatJacobInsertionSequence(pend);

	while (iterator <= pend.size()) {
		if (sequence.size() != 0 && where != 1) {
			indexsequence.push_back(sequence[0]);
			valToHade = pend[sequence[0] - 1];
			sequence.erase(sequence.begin());
			where = 1;
		} else {
			if (std::find(indexsequence.begin(), indexsequence.end(), iterator) != indexsequence.end())
				iterator++;
			indexsequence.push_back(iterator);
			valToHade = pend[iterator - 1];
			where = 2;
		}
		it = std::lower_bound(s.begin(), s.end(), valToHade);
		s.insert(it, valToHade);
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

	// time to had pend in s

	size_t iterator = 0;
	std::list<size_t> indexsequence;
	indexsequence.push_back(1);
	int where = 0;
	unsigned long valToHade;

	std::list<size_t> sequence = creatJacobInsertionSequence(pend);
	std::list<size_t>::iterator itSequence;
	std::list<size_t>::iterator itPend;
	std::list<size_t>::iterator itS;

	while (iterator <= pend.size()) {
		itSequence = sequence.begin();
		itPend = pend.begin();
		if (sequence.size() != 0 && where != 1) {

			indexsequence.push_back(*itSequence);
			std::advance(itPend, (*itSequence) - 1);
			valToHade = *itPend;
			sequence.erase(sequence.begin());
			where = 1;
		} else {
			if (std::find(indexsequence.begin(), indexsequence.end(), iterator) != indexsequence.end())
				iterator++;
			indexsequence.push_back(iterator);
			std::advance(itPend, iterator - 1);
			valToHade = *itPend;
			where = 2;
		}
		itS = std::lower_bound(s.begin(), s.end(), valToHade);
		s.insert(itS, valToHade);
		iterator++;
	}
	if (isOdd) {
		itS = std::lower_bound(s.begin(), s.end(), straggler);
		s.insert(itS, straggler);
	}
	return s;
}






