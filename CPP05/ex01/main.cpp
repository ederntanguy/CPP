#include "all.hpp"

int main ()
{
	Bureaucrat jlp("Jean-Louis-Philippe", 10);
	std::cout << jlp.getGrade() << std::endl;
	std::cout << jlp.getName() << std::endl;
	for (int i = 0; i < 10; ++i) {
		jlp.incrementGrade();
	}
	Bureaucrat herve("herve", 750);
	Bureaucrat herve2("herve", -10);
	Bureaucrat c91lp("cortex 91 les pyramindes", 145);
	for (int i = 0; i < 6; ++i) {
		c91lp.decrementGrade();
	}

	return 0;
}
