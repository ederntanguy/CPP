#include "StaticScalarConverter.hpp"

#include <stdlib.h>

#include "ownFonction.hpp"

StaticScalarConverter::StaticScalarConverter() {}


StaticScalarConverter::StaticScalarConverter(const StaticScalarConverter &src)
{
	*this = src;
}

StaticScalarConverter::~StaticScalarConverter() {}


void StaticScalarConverter::convert(std::string &value)
{
	if (value == "nan" || value == "nanf" || value == "+inf" || value == "+inff"
			|| value == "-inf" || value == "-inff")
	{
		if (value[value.length() - 1] == 'f' && value != "+inf"  && value != "-inf")
		{
			std::cout << "char: impossible" << value << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << value << std::endl;
			std::cout << "double: ";
			for (int i = 0; i < static_cast<int>(value.length()) - 1; ++i) {
				std::cout << value[i];
			}
			std::cout << std::endl;
			return;
		}
		std::cout << "char: impossible" << value << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
		return;
	}
	if (charShwoable(value))
	{
		std::cout << "char: " << value << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	int notVal = 1;
	ft_atoi(value, notVal);
	if (notVal == 1)
	{
		int intValue = ft_atoi(value, notVal);
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
		return;
	}
	notVal = 1;
	ft_atod(value, notVal);
	if (notVal == 1)
	{

		double intValue = ft_atod(value, notVal);
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(intValue) << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << "f" << std::endl;
		std::cout << "double: " << intValue << std::endl;
		return;
	}
	notVal = 1;
	ft_atof(value, notVal);
	if (notVal == 1)
	{
		float intValue = ft_atof(value, notVal);
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(intValue) << std::endl;
		std::cout << "float: " <<intValue << "f" << std::endl;
		std::cout << "double: " << static_cast<double >(intValue) << std::endl;
	}
}

StaticScalarConverter &
StaticScalarConverter::operator=(const StaticScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}