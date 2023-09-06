#include "StaticScalarConverter.hpp"

#include <stdlib.h>

#include "ownFonction.hpp"



StaticScalarConverter::StaticScalarConverter() : _value(0) {}

StaticScalarConverter::StaticScalarConverter(std::string value) : _value(value) {}

StaticScalarConverter::StaticScalarConverter(const StaticScalarConverter &src)
{
	*this = src;
}

StaticScalarConverter::~StaticScalarConverter() {}


void StaticScalarConverter::convert(std::string &value)
{
	if (charShwoable(value))
	{
		std::cout << "char: " << value << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;

	}
	int notVal = 1;
	ft_atoi(value, notVal);
	if (notVal == 1)
	{
		int intValue = atoi(value.c_str());
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << std::endl;
		std::cout << "float: " << static_cast<double>(intValue) << std::endl;
	}
}

StaticScalarConverter &
StaticScalarConverter::operator=(const StaticScalarConverter &rhs)
{
	this->_value = rhs._value;
	return *this;
}
