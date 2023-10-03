#include <iostream>
#include <ctime>
#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main ()
{
	srand(time(0));
	Intern someRandomIntern;
	Bureaucrat jlp("Jean-Louis-Philippe", 5);
	Bureaucrat cortex("cortex", 146);
	AForm *amaizing = someRandomIntern.makeForm("shruberry creation", "alexis");
	AForm *robo = someRandomIntern.makeForm("robotomy request", "gaetoutou");
	AForm *forgive = someRandomIntern.makeForm("presidential Pardon", "seydoudou");
	AForm *sdfmngkjs = someRandomIntern.makeForm("presidesdfntsdfgifdaglPardsdddfgon", "uloulou");
	(void)sdfmngkjs;
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
	amaizing->execute(cortex);
	jlp.signForm(*robo);
	jlp.executeForm(*robo);
	std::cout << *robo;
	jlp.signForm(*forgive);
	cortex.executeForm(*forgive);
	jlp.executeForm(*forgive);
	delete amaizing;
	delete robo;
	delete forgive;
	return 0;
}
