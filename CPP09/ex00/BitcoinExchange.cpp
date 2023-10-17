#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>

#include <stdlib.h>

double getDifBetweenTwoDate(std::string date1, std::string date2) {
	struct tm date1InSec = {0,0,0,0,0,0,0,0,0,0,0};
	struct tm date2InSec = {0,0,0,0,0,0,0,0,0,0,0};

	// set time date1
	date1InSec.tm_year = atoi(date1.substr(0, date1.find('-')).c_str());
	date1 = date1.substr(date1.find('-') + 1, date1.length());
	date1InSec.tm_mon = atoi(date1.substr(0, date1.find('-')).c_str());
	date1 = date1.substr(date1.find('-') + 1, date1.length());
	date1InSec.tm_mday = atoi(date1.c_str());
	// set time date2
	date2InSec.tm_year = atoi(date2.substr(0, date2.find('-')).c_str());
	date2 = date2.substr(date2.find('-') + 1, date2.length());
	date2InSec.tm_mon = atoi(date2.substr(0, date2.find('-')).c_str());
	date2 = date2.substr(date2.find('-') + 1, date2.length());
	date2InSec.tm_mday = atoi(date2.c_str());

	return difftime(mktime(&date2InSec),
					mktime(&date1InSec));
}

int errorGestion(std::string &line, double &value, std::string &date) {
	int count = 0;
	std::string tmpline = line;
	if (line.find('|') == std::string::npos ) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	while (tmpline.find('-') != std::string::npos && tmpline.find('-') < tmpline.find('|')) {
		tmpline = tmpline.substr(tmpline.find('-') + 1, tmpline.length());
		count++;
	}
	tmpline = line;
	if (count != 2) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	tmpline = tmpline.substr(tmpline.find('-') + 1, tmpline.length());
	if (tmpline.find('-') != 2 || atoi(tmpline.substr(0, 2).c_str()) > 12) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	tmpline = tmpline.substr(tmpline.find('-') + 1, tmpline.length());
	if (tmpline.find(' ') != 2 || atoi(tmpline.substr(0, 2).c_str()) > 31) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	tmpline = tmpline.substr(tmpline.find(' ') + 1, tmpline.length());
	if (tmpline.find(' ') == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	tmpline = tmpline.substr(tmpline.find('|') + 1, tmpline.length());
	value = atof(tmpline.c_str());
	if (value < 0) {
		std::cerr << "Error: not a positive number" << std::endl;
		return 0;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number" << std::endl;
		return 0;
	}
	date = line.substr(0, line.find(" "));
	return 1;
}

BitcoinExchange::BitcoinExchange() {}

//BitcoinExchange::BitcoinExchange(std::string *data, std::string *inputFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	this->_data.clear();
	std::map<std::string, double>::const_iterator it;
	for (it = rhs._data.begin(); it != rhs._data.end(); ++it) {
		this->_data.insert(std::make_pair(it->first, it->second));
	}
	return *this;
}

void BitcoinExchange::creatData(std::fstream &fileData)
{
	std::string line;
	std::string first;
	double second;
	if (fileData.is_open()) {
		this->_data.clear();
		std::getline(fileData, line);
		while (getline(fileData, line)) {
			first = line.substr(0, line.find(','));
			second = atof(line.substr(line.find(',') + 1, line.length()).c_str());
			this->_data.insert(std::make_pair(first, second));
		}
	}
}

void BitcoinExchange::showResult(std::fstream &inputFile)
{
	std::string line;
	std::string date;
	double minDeltaTime;
	double value;
	std::string indexCloser;
	if (inputFile.is_open()) {
		std::getline(inputFile, line);
		while (getline(inputFile, line)) {
			if (errorGestion(line, value, date) == 0)
				continue;
			std::cout << date << " => " << value << " = ";
			if (this->_data.begin() == this->_data.end()) {
				std::cerr << "there is no info in the data file" << std::endl;
				return;
			}
			minDeltaTime = getDifBetweenTwoDate(this->_data.begin()->first, date);
			indexCloser = this->_data.begin()->first;
			std::map<std::string, double>::const_iterator it;
			for (it = this->_data.begin(); it != this->_data.end(); ++it) {
				double tmp = getDifBetweenTwoDate(it->first, date);
				if (tmp < minDeltaTime && tmp >= 0) {
					indexCloser = it->first;
					minDeltaTime = tmp;
				}
				if (tmp <= 0) {
					break;
				}
			}
			std::cout << this->_data[indexCloser] * value << std::endl;
		}
	}
}
