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

#include "Serializer.hpp"

int main() {
	Serializer transform;
	uintptr_t tmp;
	Data *tmp2;
	Data *value = new Data;
	value->num1 = 5;
	value->val = "ajgsdf";
	std::cout << value->num1 << " " << value->val << std::endl;
	tmp = transform.serialize(value);
	tmp2 = transform.deserialize(tmp);
	std::cout << tmp2->num1 << " " << tmp2->val << std::endl;
	std::cout << tmp2 << " " << value << std::endl;
	delete value;
	return 0;
}