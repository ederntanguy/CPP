#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

#include "all.hpp"

class PresidentialPardonForm : public AForm{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &name, int gradeForSign, int gradeForExecute, const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

private:
	const std::string _target;
};


#endif //CPP05_PRESIDENTIALPARDONFORM_HPP
