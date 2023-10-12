#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void creatData(std::fstream &fileData);
private:
	std::map<std::string, double> data;
};


#endif //CPP09_BITCOINEXCHANGE_HPP
