/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:37:26 by etanguy           #+#    #+#             */
/*   Updated: 2023/09/05 15:37:26 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "StaticScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return 0;
	StaticScalarConverter a;
	std::string tmp = argv[1];
	a.convert(tmp);
	return 0;
}