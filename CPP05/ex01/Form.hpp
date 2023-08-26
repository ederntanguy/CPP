#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include "all.hpp"

class Form {
public:
	Form();
	Form(const Form &src);
	~Form();

	Form &operator=(const Form &rhs);

	class GradeTooHighException : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "this grade gonna be to higher";
		}
	};

	class GradeTooLowException : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "this grade gonna be to lower";
		}
	};

private:
	const std::string _name;
	bool _sign;
	int _gradeForSign;
	int _gradeForExecute;
};

std::ostream &operator<<(std::ostream &o, const Form &i);

#endif //CPP05_FORM_HPP
