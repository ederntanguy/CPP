#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(), _grade(75) {}

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

void Bureaucrat::signForm(AForm &formulaire) {
	try {
		formulaire.beSigned(*this);
		std::cout << this->_name << " signed " << formulaire.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "couldn’t sign " << formulaire.getName() << " because the bureaucrat level is to low" << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "looser " << this->_name << ", your grade is too low" << std::endl;
	}
	catch (AForm::DocuementNotSigned &e) {
		e.thereIsAnIssue();
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i) {
	o << i.getName() << " bureaucrat grade " << i.getGrade();
	return o;
}
