#ifndef EX01_RPN_HPP
#define EX01_RPN_HPP

#include <stack>
#include <iostream>

class RPN {
public:
	RPN();
	RPN(const RPN &src);
	~RPN();

	RPN &operator=(const RPN &rhs);
	void	addOperand(int operand);
	void	addOperator(char operatorInput);
	void	showActualResult() const;
	size_t	stackSize() const;
private:
	std::stack<int> _operand;
};


#endif //EX01_RPN_HPP
