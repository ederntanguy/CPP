#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(std::string *data, std::string *inputFile);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange &operator=(const BitcoinExchange &rhs);
private:
	std::map<std::string, std::string> _information;
	std::string *_data;
	std::string *_inputFile;
};


#endif //CPP09_BITCOINEXCHANGE_HPP
