#ifndef EX00_STATICSCALARCONVERTER_HPP
#define EX00_STATICSCALARCONVERTER_HPP

#include <iostream>

class StaticScalarConverter {
public:
	StaticScalarConverter();
	StaticScalarConverter(std::string value);
	StaticScalarConverter(const StaticScalarConverter &src);
	~StaticScalarConverter();

	StaticScalarConverter &operator=(const StaticScalarConverter &rhs);

	static void convert(std::string &value);
private:
	std::string _value;
};


#endif //EX00_STATICSCALARCONVERTER_HPP
