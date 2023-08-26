#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, int gradeForSign, int gradeForExecute, const std::string &target) :
		AForm(name, gradeForSign, gradeForExecute), _target(target) {}

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
