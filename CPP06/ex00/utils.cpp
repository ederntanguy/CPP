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
#include <iostream>

int ft_atoi(std::string val, int &notVal)
{
	int j = 0;
	while (val[j] == '+' || val[j] == '+')
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
	if (val[i] == '+' || val[i] == '-')
	{
		if (val[i] == '-')
			neg *= -1;
		i++;
	}
	while (i < static_cast<int>(val.length()) && val[i])
	{
		res = res * 10 + val[i];
		i++;
	}
	if (res < -2147483648 || res > 2147483647)
	{
		notVal = 0;
		return 0;
	}
	return res * neg;
}

int ft_atof(std::string val, int &notVal)
{
	int countPoint = 0;
	int j = 0;
	while (val[j] == '+' || val[j] == '+')
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
	long res;
	if (val[i] == '+' || val[i] == '-')
	{
		if (val[i] == '-')
			neg *= -1;
		i++;
	}
	while (i < static_cast<int>(val.length()) && val[i])
	{
		res = res * 10 + val[i];
		i++;
	}
	if (res < -2147483648 || res > 2147483647)
	{
		notVal = 0;
		return 0;
	}
	return res * neg;
}

int charShwoable(std::string value) {
	if (value.length() == 1 && ((value[0] >= 32 && value[0] <= 47) || (value[0] >= 58 && value[0] <= 126)))
		return 1;
	return 0;
}