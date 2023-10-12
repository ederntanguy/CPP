#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(NULL), _inputFile(NULL) {}

BitcoinExchange::BitcoinExchange(std::string *data, std::string *inputFile) : _data(data), _inputFile(inputFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	int i = 0;
	while (rhs._data[i] != "")
	return *this;
}
