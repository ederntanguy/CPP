#include <iostream>
#include <string>
#include <cstdlib>

#include "PmergeMe.hpp"

int vectorPart(std::vector<unsigned long> &initalVector) {
	PmergeMe makeOperation;
	bool isOdd = initalVector.size() % 2;
	unsigned long lastVal = initalVector[initalVector.size() - 1];
	(void)lastVal;
	if (isOdd)
		initalVector.pop_back();
	std::vector<std::pair<unsigned long, unsigned long> > pairedArray = makeOperation.makePair(initalVector);
	makeOperation.sortInPairs(pairedArray);
	makeOperation.pairsInsertionSort(pairedArray, pairedArray.size() - 1);
	for (size_t i = 0; i < pairedArray.size(); ++i) {
		std::cout << pairedArray[i].first << ", " << pairedArray[i].second << std::endl;
	}

	return 0;
}

int listPart(std::list<unsigned long> &initallist) {
	PmergeMe makeOperation;
	bool isOdd = initallist.size() % 2;
	unsigned long lastVal = initallist.back();
	(void)lastVal;
	if (isOdd)
		initallist.pop_back();
	std::list<std::pair<unsigned long, unsigned long> > pairedArray = makeOperation.makePair(initallist);

	makeOperation.sortInPairs(pairedArray);

	std::list<std::pair<unsigned long, unsigned long> >::const_iterator it;
	std::list<std::pair<unsigned long, unsigned long> >::const_iterator ite = pairedArray.end();
	for (it = pairedArray.begin(); it != ite; ++it) {
		std::cout << (*it).first << ", " << (*it).second << std::endl;
	}

	return 0;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Error: please enter some values" << std::endl;
		return 1;
	}
	int i = 1;
	int j;
	unsigned long tmp;
	std::vector<unsigned long> initialVector;
	std::list<unsigned long> initialList;
	while (argv[i]) {
		j = 0;
		while (argv[i][j]) {
			if (!isdigit(argv[i][j])) {
				std::cerr << "Error: please enter valide unisgned values" << std::endl;
				return 1;
			}
			j++;
		}
		tmp = std::strtoul(argv[i], NULL, 10);
		initialVector.push_back(tmp);
		initialList.push_back(tmp);
		i++;
	}

	// vector part
	std::cout << "-----vector-----" << std::endl;
	vectorPart(initialVector);

	// list part
	std::cout << "-----list-----" << std::endl;
	listPart(initialList);

	return 0;
}