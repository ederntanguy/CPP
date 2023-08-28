#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	void execute(Bureaucrat const &executor) const;

private:
	const std::string _target;
};


#endif //CPP05_PRESIDENTIALPARDONFORM_HPP
