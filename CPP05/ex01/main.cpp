#include "all.hpp"

int main ()
{
	Bureaucrat jlp("Jean-Louis-Philippe", 10);
	Form attestation("sport", 50 , 30);
	Form dedicace("pour mes fanes", 149 , 110);
	Form bombenNucleaire("BOOM", 5 , 1);

	std::cout << "\n" << dedicace << std::endl;

	jlp.signForm(attestation);
	jlp.signForm(attestation);
	jlp.signForm(bombenNucleaire);
	for (int i = 0; i < 7; ++i)
	{
		jlp.incrementGrade();
	}
	jlp.signForm(bombenNucleaire);
	jlp.signForm(dedicace);

	std::cout << "\n" << dedicace << std::endl;

	return 0;
}
