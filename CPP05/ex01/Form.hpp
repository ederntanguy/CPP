#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include "all.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string &name, int gradeForSign, int gradeForExecute);
	Form(const Form &src);
	~Form();

	Form &operator=(const Form &rhs);

	void beSigned(Bureaucrat &person);
	std::string getName() const;
	bool getSign() const;
	int getGradeForSign() const;
	int getGradeForExecute() const;
	class GradeTooHighException : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "this grade is to higher";
		}
	};

	class GradeTooLowException : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "this grade is to lower";
		}
	};

private:
	const std::string _name;
	int _gradeForExecute;
	int _gradeForSign;
	bool _sign;
};

std::ostream &operator<<(std::ostream &o, const Form &i);

#endif //CPP05_FORM_HPP
