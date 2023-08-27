#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main ()
{
	Bureaucrat jlp("Jean-Louis-Philippe", 10);
	Bureaucrat alexis("Jean-Louis-Philippe", 146);
	AForm *amaizing = new ShrubberyCreationForm("alexis");

	amaizing->execute(jlp);
	amaizing->beSigned(jlp);
	amaizing->execute(jlp);
	return 0;
}
