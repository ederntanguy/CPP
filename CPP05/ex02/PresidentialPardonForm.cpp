#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	this->_sign = rhs.getSign();
	this->_gradeForExecute = rhs.getGradeForExecute();
	this->_gradeForSign = rhs.getGradeForSign();
	return *this;
}
