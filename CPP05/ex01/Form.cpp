#include "Form.hpp"

Form::Form() : _name(""), _gradeForExecute(0), _gradeForSign(75), _sign(false) {}

Form::Form(std::string name, int gradeForSign, int gradeForExecute) : _name(name), _sign(false) {
	try {
		if (gradeForExecute > 150)
		{
			std::cout << "probleme with gradeForExecute ";
			throw Form::GradeTooLowException();
		}
		else if (gradeForExecute < 1)
		{
			std::cout << "probleme with gradeForExecute ";
			throw Form::GradeTooHighException();
		}
		this->_gradeForExecute = gradeForExecute;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	try {
		if (gradeForSign > 150)
		{
			std::cout << "probleme with gradeForSign ";
			throw Form::GradeTooLowException();
		}
		else if (gradeForSign < 1)
		{
			std::cout << "probleme with gradeForSign ";
			throw Form::GradeTooHighException();
		}
		this->_gradeForSign = gradeForSign;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
}


Form::Form(const Form &src) {
	*this = src;
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs) {
	this->_sign = rhs._sign;
	this->_gradeForExecute = rhs._gradeForExecute;
	this->_gradeForSign = rhs._gradeForSign;
	return *this;
}

void Form::beSigned(Bureaucrat person) {
	try {
		if (static_cast<int>(person.getGrade()) > this->_gradeForExecute)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << "shit " << person.getName() << " not grade enough" << std::endl;
	}
	if (this->_sign) {
		std::cout << "the document is allready signed" << std::endl;
		return;
	}
	this->_sign = true;
	std::cout << "the form be signed" << std::endl;

}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSign() const {
	return this->_sign;
}

int Form::getGradeForSign() const {
	return this->_gradeForSign;
}

int Form::getGradeForExecute() const {
	return this->_gradeForExecute;
}

void Form::setSign(bool value) {
	this->_sign = value;
}

std::ostream &operator<<(std::ostream &o, const Form &i) {
	o << "the formulaire " << i.getName() << " need a grade " << i.getGradeForSign()
	<< " or highter to be sign, and need a grade " << i.getGradeForExecute()
	<< " or highter to be execute, and the sign cas is actually ";
	if (i.getSign())
		std::cout << "signed" << std::endl;
	else
		std::cout << "not signed" << std::endl;
	return o;
}
