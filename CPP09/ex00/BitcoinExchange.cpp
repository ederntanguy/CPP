#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>

#include <stdlib.h>

double getDifBetweenTwoDate(std::string date1, std::string date2) {
	struct tm date1InSec;
	struct tm date2InSec;

	// set time date1
	date1InSec.tm_year = atoi(date1.substr(0, date1.find("-")).c_str());
	date1InSec.tm_mon = atoi(date1.substr(5, 7).c_str());
	date1InSec.tm_mday = atoi(date1.substr(8, date1.length()).c_str());
	date1InSec.tm_hour = 0; date1InSec.tm_min = 0; date1InSec.tm_sec = 0;
	// set time date2
	date2InSec.tm_year = atoi(date2.substr(0, date2.find("-")).c_str());
	date2InSec.tm_mon = atoi(date2.substr(5, 7).c_str());
	date2InSec.tm_mday = atoi(date2.substr(8, date2.length()).c_str());
	date2InSec.tm_hour = 0; date2InSec.tm_min = 0; date2InSec.tm_sec = 0;

	return difftime(mktime(&date2InSec),mktime(&date1InSec));
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
//		std::map<std::string, double>::const_iterator it;
//		for (it = this->_data.begin(); it != this->_data.end(); ++it) {
//			std::cout << it->first << "," << it->second << std::endl;
//		}
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
			date = line.substr(0, line.find(" "));
			value = atof(line.substr(line.find(" ") + 3 , line.length()).c_str());
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
					minDeltaTime = getDifBetweenTwoDate(it->first, date);
				}
			}
			std::cout << this->_data[indexCloser] * value << std::endl;
		}
	}
}
