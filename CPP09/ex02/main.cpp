#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "PmergeMe.hpp"

int vectorPart(std::vector<unsigned long> &initalVector) {
	clock_t begin = clock();
	PmergeMe makeOperation;
	bool isOdd = initalVector.size() % 2;
	unsigned long lastVal = initalVector[initalVector.size() - 1];
	(void)lastVal;

	std::vector<unsigned long> sortedArray;

	if (isOdd)
		initalVector.pop_back();
	std::vector<std::pair<unsigned long, unsigned long> > pairedArray = makeOperation.makePair(initalVector);
	makeOperation.sortInPairs(pairedArray);
	makeOperation.pairsInsertionSort(pairedArray, pairedArray.size() - 1);
	sortedArray = makeOperation.creatSortedArray(pairedArray, lastVal, isOdd);
	clock_t end = clock();
	std::cout << "After:";
	for (size_t k = 0; k < sortedArray.size() && k < 5; ++k) {
		std::cout << " " << sortedArray[k];
	}
	if (sortedArray.size() > 5)
		std::cout << " [...]";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << sortedArray.size() << " elements with std::vector : " << double(end - begin) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
//	for (size_t i = 0; i < sortedArray.size(); ++i)
//	{
//		std::cout << sortedArray[i] << " ";
//		if (i % 20 == 0 && i != 0)
//			std::cout << std::endl;
//	}
	return 0;
}

int listPart(std::list<unsigned long> &initallist) {
	clock_t begin = clock();
	PmergeMe makeOperation;
	bool isOdd = initallist.size() % 2;
	unsigned long lastVal = initallist.back();
	(void)lastVal;

	std::list<unsigned long> sortedArray;

	if (isOdd)
		initallist.pop_back();
	std::list<std::pair<unsigned long, unsigned long> > pairedArray = makeOperation.makePair(initallist);

	makeOperation.sortInPairs(pairedArray);
	makeOperation.pairsInsertionSort(pairedArray, pairedArray.size() - 1);

	sortedArray = makeOperation.creatSortedArray(pairedArray, lastVal, isOdd);

	clock_t end = clock();
	std::cout << "Time to process a range of " << sortedArray.size() << " elements with std::list : " << double(end - begin) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

//	std::list<unsigned long>::const_iterator it;
//	std::list<unsigned long>::const_iterator ite = sortedArray.end();
//	for (it = sortedArray.begin(); it != ite; ++it) {
//		std::cout << *it << std::endl;
//	}

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
		if (std::find(initialVector.begin(), initialVector.end(), tmp) == initialVector.end()) {
			initialVector.push_back(tmp);
			initialList.push_back(tmp);
		}
		i++;
	}
	// vector part
	std::cout << "Before:";
	for (size_t k = 0; k < initialVector.size() && k < 5; ++k) {
		std::cout << " " << initialVector[k];
	}
	if (initialVector.size() > 5)
		std::cout << " [...]";
	std::cout << std::endl;
	vectorPart(initialVector);

	// list part
	listPart(initialList);

	return 0;
}