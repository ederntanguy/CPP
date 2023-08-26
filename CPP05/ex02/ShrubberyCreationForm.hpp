#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include "all.hpp"

class ShrubberyCreationForm : public AForm{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &name, int gradeForSign, int gradeForExecute, const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

private:
	const std::string _target;
};


#endif //CPP05_SHRUBBERYCREATIONFORM_HPP
