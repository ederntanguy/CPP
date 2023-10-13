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
	std::vector<std::pair<unsigned long, unsigned long> >  makePair(std::vector<unsigned long > input);
	std::list<std::pair<unsigned long, unsigned long> >  makePair(std::list<unsigned long > input);
};


#endif //CPP09_PMERGEME_HPP
