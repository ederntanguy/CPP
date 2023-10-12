#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <fstream>
#include <iostream>

#include <stdlib.h>

BitcoinExchange::BitcoinExchange() {}

//BitcoinExchange::BitcoinExchange(std::string *data, std::string *inputFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	this->data.clear();
	std::map<std::string, double>::const_iterator it;
	for (it = rhs.data.begin(); it != rhs.data.end(); ++it) {
		this->data.insert(std::make_pair(it->first, it->second));
	}
	return *this;
}

void BitcoinExchange::creatData(std::fstream &fileData)
{
	std::string line;
	if (fileData.is_open()) {
		this->data.clear();
		std::getline(fileData, line);
		while (getline(fileData, line)) {
			std::string first;
			double second;
			first = line.substr(0, line.find(','));
			second = atof(line.substr(line.find(',') + 1, line.length()).c_str());
			this->data.insert(std::make_pair(first, second));
		}
		std::map<std::string, double>::const_iterator it;
		for (it = this->data.begin(); it != this->data.end(); ++it) {
			std::cout << it->first << "," << it->second << std::endl;
		}
	}
}
