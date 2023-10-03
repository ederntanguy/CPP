/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:20:28 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/06 13:20:28 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <float.h>
#include <iostream>

int ft_atoi(std::string val, int &notVal)
{
	if (val.length() > 11)
	{
		notVal = 0;
		return 0;
	}
	int j = 0;
	while (j < static_cast<int>(val.length()) && (val[j] == '+' || val[j] == '-'))
		j++;
	for (int j = 0; j < static_cast<int>(val.length()); ++j)
	{
		if (isdigit(val[j]))
		{
			notVal = 0;
			return 0;
		}
	}
	int i = 0;
	int neg = 1;
	long res;
	if (j < static_cast<int>(val.length()) && (val[i] == '+' || val[i] == '-'))
	{
		if (val[i] == '-')
			neg *= -1;
		i++;
	}
	while (i < static_cast<int>(val.length()) && val[i])
	{
		res = res * 10 + (val[i] - '0');
		i++;
	}
	res = res * neg;
	if (res < -2147483648 || res > 2147483647)
	{
		notVal = 0;
		return 0;
	}
	return res;
}

double ft_atod(std::string val, int &notVal)
{
	int countPoint = 0;
	int j = 0;
	if (j < static_cast<int>(val.length()) && (val[j] == '+' || val[j] == '-'))
		j++;
	while (j < static_cast<int>(val.length()))
	{
		if (!(isdigit(val[j]) || (val[j] == '.' && countPoint == 0)))
		{
			notVal = 0;
			return 0;
		}
		if (val[j] == '.')
			countPoint++;
		j++;
	}
	int i = 0;
	int neg = 1;
	double res = 0;
	if (i < static_cast<int>(val.length()) && (val[i] == '+' || val[i] == '-'))
	{
		if (val[i] == '-')
			neg *= -1;
		i++;
	}

	int afterPoint = 0;
	while (i < static_cast<int>(val.length()) && val[i])
	{
		if (val[i] == '.')
		{
			i++;
			afterPoint = 10;
		}
		if (afterPoint == 0)
		{
			if ((res * 10 +(val[i] - '0')) * neg < -DBL_MAX || ( res * 10 + (val[i] - '0')) * neg > DBL_MAX)
			{
				notVal = 0;
				return 0;
			}
			res = res * 10 + (val[i] - '0');
		}
		else
		{
			if ((res + static_cast<double>(val[i] - '0') / static_cast<double>(afterPoint)) * neg < -DBL_MAX
			|| ((res + static_cast<double>(val[i] - '0') / static_cast<double>(afterPoint)) * neg > DBL_MAX))
			{
				notVal = 0;
				return 0;
			}
			res = res + static_cast<double>(val[i] - '0') / static_cast<double>(afterPoint);
			afterPoint *= 10;
		}
		i++;
	}
	res = res * neg;
	return res;
}

void showChar(char value) {
	std::cout << "char: ";
	if (value >= 32 && value < 127)
		std::cout << "'" << value << "'" << std::endl;
	else if (value >= 0)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void showSpecial(std::string value) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (value == "inff" || value == "-inff" || value == "nanf") {
		std::cout << "float: " << value << std::endl;
		value = value.substr(0, value.length() - 1);
		std::cout << "double: " << value << std::endl;
	} else {
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}

}