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
#include <time.h>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	srand(time(0));
	int i = rand() % 3;
	if (i == 0)
		return static_cast
}

void identify(Base* p) {

}

void identify(Base& p) {

}

int main() {

	return 0;
}