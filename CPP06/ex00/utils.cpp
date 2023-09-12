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
	while (j < static_cast<int>(val.length()) && (val[j] == '+' || val[j] == '-'))
		j++;
	for (int j = 0; j < static_cast<int>(val.length()); ++j)
	{
		if (!(isdigit(val[j]) || (val[j] == '.' && countPoint == 0)))
		{
			notVal = 0;
			return 0;
		}
		if (val[j] == '.')
			countPoint++;
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
			if ((res * 10 +(val[i] - '0')) * neg < DBL_MIN || ( res * 10 + (val[i] - '0')) * neg > DBL_MAX)
			{
				notVal = 0;
				return 0;
			}
			res = res * 10 + (val[i] - '0');
		}
		else
		{
			if ((res + static_cast<double>(val[i] - '0') / static_cast<double>(afterPoint)) * neg < DBL_MIN
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

float ft_atof(std::string val, int &notVal)
{
	int countPoint = 0;
	int j = 0;
	while (j < static_cast<int>(val.length()) && (val[j] == '+' || val[j] == '-'))
		j++;
	for (int j = 0; j < static_cast<int>(val.length()); ++j)
	{
		if (!(isdigit(val[j]) || (val[j] == '.' && countPoint == 0) || (j + 1 == static_cast<int>(val.length()) && val[j] == 'f')))
		{
			notVal = 0;
			return 0;
		}
		if (val[j] == '.')
			countPoint++;
	}
	int i = 0;
	int neg = 1;
	float res;
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
			if ((res * 10 + (val[i] - '0')) * neg < FLT_MIN || ( res * 10 + (val[i] - '0')) * neg > FLT_MAX)
			{
				notVal = 0;
				return 0;
			}
			res = res * 10 + (val[i] - '0');
		}
		else
		{
			if ((res + static_cast<double>(val[i] - '0') / static_cast<double>(afterPoint)) * neg < FLT_MIN
			|| ((res + static_cast<double>(val[i] - '0') / static_cast<double>(afterPoint)) * neg > FLT_MAX))

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

int charShwoable(std::string value) {
	if (value.length() == 1 && ((value[0] >= 32 && value[0] <= 47) || (value[0] >= 58 && value[0] <= 126)))
		return 1;
	return 0;
}