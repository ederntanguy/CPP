#include "all.hpp"

int main ()
{
	Bureaucrat jlp("Jean-Louis-Philippe", 10);
	Form attestation("feur", 50 , 30);
	Form dedicace("pour mes fanes", 149 , 110);
	Form bombenNucleaire("BOOM", 5 , 1);

	std::cout << "\n" << dedicace << std::endl;

	attestation.beSigned(jlp);
	jlp.signForm(attestation);
	jlp.signForm(attestation);
	jlp.signForm(bombenNucleaire);
	jlp.signForm(dedicace);
	bombenNucleaire.beSigned(jlp);
	dedicace.beSigned(jlp);

	std::cout << "\n" << dedicace << std::endl;

	return 0;
}
