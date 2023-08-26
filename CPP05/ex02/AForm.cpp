#include "AForm.hpp"

AForm::AForm() : _name(""), _gradeForExecute(0), _gradeForSign(75), _sign(false) {}

AForm::AForm(const std::string &name, int gradeForSign, int gradeForExecute) : _name(name), _sign(false) {
	try {
		if (gradeForExecute > 150)
		{
			std::cout << "probleme with gradeForExecute ";
			throw AForm::GradeTooLowException();
		}
		else if (gradeForExecute < 1)
		{
			std::cout << "probleme with gradeForExecute ";
			throw AForm::GradeTooHighException();
		}
		this->_gradeForExecute = gradeForExecute;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	try {
		if (gradeForSign > 150)
		{
			std::cout << "probleme with gradeForSign ";
			throw AForm::GradeTooLowException();
		}
		else if (gradeForSign < 1)
		{
			std::cout << "probleme with gradeForSign ";
			throw AForm::GradeTooHighException();
		}
		this->_gradeForSign = gradeForSign;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
}


AForm::AForm(const AForm &src) {
	*this = src;
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs) {
	this->_sign = rhs._sign;
	this->_gradeForExecute = rhs._gradeForExecute;
	this->_gradeForSign = rhs._gradeForSign;
	return *this;
}

void AForm::beSigned(Bureaucrat &person) {
	try {
		if (static_cast<int>(person.getGrade()) > this->_gradeForExecute)
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "shit " << person.getName() << " not grade enough" << std::endl;
	}
	if (this->_sign) {
		std::cout << "the document is allready signed" << std::endl;
		return;
	}
	this->_sign = true;
	std::cout << "the form be signed by " << person.getName() << std::endl;

}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSign() const {
	return this->_sign;
}

int AForm::getGradeForSign() const {
	return this->_gradeForSign;
}

int AForm::getGradeForExecute() const {
	return this->_gradeForExecute;
}

void AForm::setSign(bool value) {
	this->_sign = value;
}

std::ostream &operator<<(std::ostream &o, const AForm &i) {
	o << "the formulaire " << i.getName() << " need a grade " << i.getGradeForSign()
	  << " or highter to be sign, and need a grade " << i.getGradeForExecute()
	  << " or highter to be execute, and the sign cas is actually ";
	if (i.getSign())
		std::cout << "signed" << std::endl;
	else
		std::cout << "not signed" << std::endl;
	return o;
}
