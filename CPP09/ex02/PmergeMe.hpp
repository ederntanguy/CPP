#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);
	std::vector<std::pair<unsigned long, unsigned long> >  makePair(std::vector<unsigned long > input) const;
	std::list<std::pair<unsigned long, unsigned long> >  makePair(std::list<unsigned long > input) const;
	void sortInPairs(std::vector<std::pair<unsigned long, unsigned long> > &values) const;
	void sortInPairs(std::list<std::pair<unsigned long, unsigned long> > &values) const;
	void pairsInsertionSort(std::vector<std::pair<unsigned long, unsigned long> > &values, int pos) const;
	void pairsInsertionSort(std::list<std::pair<unsigned long, unsigned long> > &values, int pos) const;
	void insertPairs(std::pair<unsigned long, unsigned long> element, std::vector<std::pair<unsigned long, unsigned long> > &values, int pos) const;
	void insertPairs(std::pair<unsigned long, unsigned long> element, std::list<std::pair<unsigned long, unsigned long> > &values, int pos, std::list<std::pair<unsigned long, unsigned long> >::iterator itPosSend, int isSend) const;
	std::vector<unsigned long> creatSortedArray(std::vector<std::pair<unsigned long, unsigned long> > &values, unsigned long straggler, bool isOdd);
	std::list<unsigned long> creatSortedArray(std::list<std::pair<unsigned long, unsigned long> > &values, unsigned long straggler, bool isOdd);

};


#endif //CPP09_PMERGEME_HPP
