#include <iostream>

#include "RPN.hpp"

int checkInput(std::string input) {
	int i = 0;
	int isSpace = 1;
	while (input[i]) {
		if ((isdigit(input[i]) || input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/') && isSpace == 1)
			isSpace = 0;
		else if (input[i] == ' ')
			isSpace = 1;
		else {
			std::cerr << "Error: not a valide input" << std::endl;
			return 1;
		}
		i++;
	}
	return 0;
}

int main(int argc, char **argv) {
	(void)argv;
	if (argc != 2) {
		std::cerr << "Error: please enter a RPN calculation" << std::endl;
		return 1;
	}
	std::string input = argv[1];
	if (checkInput(input))
		return 1;
	RPN infoTreatment;
	int i = 0;
	while (input[i]) {
		if (isdigit(input[i]))
			infoTreatment.addOperand(input[i] - '0');
		else if (input[i] != ' ') {
			if (infoTreatment.stackSize() < 2) {
				std::cerr << "Error: can't do the operation" << std::endl;
				return 1;
			}
			infoTreatment.addOperator(input[i]);
		}
		i++;
	}
	infoTreatment.showResult();
	return 0;
}