#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main ()
{
	srand(time(0));
	Bureaucrat jlp("Jean-Louis-Philippe", 5);
	Bureaucrat alexis("Jean-Louis-Philippe", 146);
	AForm *amaizing = new ShrubberyCreationForm("alexis");
	AForm *robo = new RobotomyRequestForm("gaetoutou");
	AForm *forgive = new PresidentialPardonForm("seydoudou");

	try {
		amaizing->execute(jlp);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << jlp.getName() << " have a grade to low for executed " << amaizing->getName() << std::endl;
	}
	catch (AForm::DocuementNotSigned &e) {
		e.thereIsAnIssue();
	}
	jlp.signForm(*amaizing);
	amaizing->execute(jlp);
	amaizing->execute(alexis);
	jlp.signForm(*robo);
	jlp.executeForm(*robo);
	std::cout << *robo << std::endl;
	jlp.signForm(*forgive);
	alexis.executeForm(*forgive);
	jlp.executeForm(*forgive);
	delete amaizing;
	delete robo;
	delete forgive;
	return 0;
}
