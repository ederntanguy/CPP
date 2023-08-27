#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 75, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
		AForm(target, 75, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	this->_sign = rhs.getSign();
	this->_gradeForExecute = rhs.getGradeForExecute();
	this->_gradeForSign = rhs.getGradeForSign();
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	srand(time(NULL));
	try {
		if (executor.getGrade() > this->_gradeForExecute)
			throw GradeTooLowException();
		srand(time(NULL));
		if (rand() % 2)
			std::cout << "BIP BIP BOOP BOOP PCHHHHHHIIIIT . . . . . . Mission success " << this->_target << " have been robotomised" << std::endl;
		else
			std::cout << "BIP BIP BOOP BOOP PCHHHHHHIIIIT . . . . . . Mission Failed " << this->_target << " haven't been robotomised" << std::endl;
	}
	catch (GradeTooLowException &e) {
		std::cout << "the Bureaucrat " << executor.getName() << " can't execute " << this->_name << std::endl;
	}
}
