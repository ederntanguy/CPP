#include "RPN.hpp"

#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
	for (size_t i = 0; i < rhs._operand.size(); ++i) {
		this->_operand = rhs._operand;
	}
	return *this;
}

void RPN::addOperand(int oprand) {
	this->_operand.push(oprand);
}

void RPN::addOperator(char operatorInput) {
	int tmp1 = this->_operand.top();
	this->_operand.pop();
	int tmp2 = this->_operand.top();
	this->_operand.pop();
	if (operatorInput == '+')
		this->_operand.push(tmp2 + tmp1);
	else if (operatorInput == '-')
		this->_operand.push(tmp2 - tmp1);
	else if (operatorInput == '*')
		this->_operand.push(tmp2 * tmp1);
	else if (operatorInput == '/')
		this->_operand.push(tmp2 / tmp1);
}

void RPN::showResult() const {
	if (this->_operand.size() > 1) {
		std::cerr << "Error: there are not enough operators" << std::endl;
		return;
	}
	std::cout << this->_operand.top() << std::endl;
}

size_t RPN::stackSize() const {
	return this->_operand.size();
}
