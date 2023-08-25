#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(), _grade(75) {

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->_grade = rhs.getGrade();

	return *this;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	try {
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
		std::cout << "congratulation your grade is now " << this->_grade << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}

}

void Bureaucrat::decrementGrade() {
	try {
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
		std::cout << "looser your grade is now " << this->_grade << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.thereIsAnIssue() << std::endl;
	}
}
