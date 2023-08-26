#ifndef CPP05_AFORM_HPP
#define CPP05_AFORM_HPP

#include "all.hpp"

class Bureaucrat;

class AForm{
public:
	AForm();
	AForm(const std::string &name, int gradeForSign, int gradeForExecute);
	AForm(const AForm &src);
	~AForm();

	AForm &operator=(const AForm &rhs);

	void beSigned(Bureaucrat &person);
	std::string getName() const;
	bool getSign() const;
	int getGradeForSign() const;
	int getGradeForExecute() const;
	void setSign(bool value);
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

protected:
	const std::string _name;
	int _gradeForExecute;
	int _gradeForSign;
	bool _sign;
};

std::ostream &operator<<(std::ostream &o, const AForm &i);


#endif //CPP05_AFORM_HPP
