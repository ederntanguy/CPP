#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, int gradeForSign, int gradeForExecute, const std::string &target) :
													AForm(name, gradeForSign, gradeForExecute), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	this->_sign = rhs.getSign();
	this->_gradeForExecute = rhs.getGradeForExecute();
	this->_gradeForSign = rhs.getGradeForSign();
	return *this;
}
