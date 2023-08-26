#ifndef CPP05_ROBOTOMYREQUESTFORM_HPP
#define CPP05_ROBOTOMYREQUESTFORM_HPP

#include "all.hpp"

class RobotomyRequestForm : public AForm{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &name, int gradeForSign, int gradeForExecute, const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

private:
	const std::string _target;
};


#endif //CPP05_ROBOTOMYREQUESTFORM_HPP
