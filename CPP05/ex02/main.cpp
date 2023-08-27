#include "all.hpp"

int main ()
{
	Bureaucrat jlp("Jean-Louis-Philippe", 10);
	AForm *amaizing = new ShrubberyCreationForm("alexis", "alexis");

	amaizing->execute(jlp);
	amaizing->beSigned(jlp);
	amaizing->execute(jlp);
	return 0;
}
