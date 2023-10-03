#include "Intern.hpp"

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return *this;
}

AForm *Intern::makeForm(const std::string& formType, const std::string& target)
{
	AForm *returnValue = NULL;
	std::string allForm[3] = {"robotomy request", "presidential Pardon", "shruberry creation"};
	int i = 0;
	while (i < 3 && formType != allForm[i])
		i++;
	switch (i)
	{
		case 0:
			returnValue = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << *returnValue;
			return returnValue;
		case 1:
			returnValue = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << *returnValue;
			return returnValue;
		case 2:
			returnValue = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << *returnValue;
			return new ShrubberyCreationForm(target);
	}
	std::cout << "I don't understand there is no form with this type" << std::endl;
	return returnValue;
}
