#include "StaticScalarConverter.hpp"

#include <stdlib.h>
#include <iomanip>

#include "ownFonction.hpp"

StaticScalarConverter::StaticScalarConverter() {}


StaticScalarConverter::StaticScalarConverter(const StaticScalarConverter &src)
{
	*this = src;
}

StaticScalarConverter::~StaticScalarConverter() {}


void StaticScalarConverter::convert(std::string &value)
{
	int notval = 1;

	if (value == "+inf" || value == "+inff" || value == "-inf" || value == "-inff" || value == "nan" || value == "nanf") {
		showSpecial(value);
		return;
	}
	if (value[value.length() - 1] == 'f')
		value = value.substr(0, value.length() - 1);
	double result;
	result = ft_atoi(value, notval);
	if (notval == 0) {
		notval = 1;
		result = ft_atod(value, notval);
	}
	if (notval == 0 && value.length() == 1) {
		showChar(static_cast<int>(value[0]));
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float >(value[0]) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double >(value[0]) << std::endl;
		return;
	}
	else if (notval == 0) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	showChar(static_cast<int>(result));
	std::cout << "int: " << static_cast<int>(result) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(result) << "f" << std::endl;
	std::cout << "double: "  << std::fixed << std::setprecision(1) << result << std::endl;
}

StaticScalarConverter &
StaticScalarConverter::operator=(const StaticScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}
