#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const std::vector<unsigned int>& vecInput);
	PmergeMe(const std::list<unsigned int>& listInput);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);
private:
	bool						_isOdd;
	unsigned int				_oddValue;
	std::vector<unsigned int>	_vecArray;
	std::list<unsigned int>		_listArray;
};


#endif //CPP09_PMERGEME_HPP
