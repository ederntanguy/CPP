#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern {

public:
	Intern();
	Intern(const Intern &src);
	~Intern();

	Intern &operator=(const Intern &rhs);

	static AForm *makeForm(const std::string& formType, const std::string& target);
};


#endif //CPP05_INTERN_HPP
