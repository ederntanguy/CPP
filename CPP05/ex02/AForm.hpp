#ifndef CPP05_AFORM_HPP
#define CPP05_AFORM_HPP

#include <string>

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string &name, int gradeForSign, int gradeForExecute);
	AForm(const AForm &src);
	virtual ~AForm();

	AForm &operator=(const AForm &rhs);

	virtual void execute(Bureaucrat const & executor) const = 0;
	void beSigned(Bureaucrat &person);
	std::string getName() const;
	bool getSign() const;
	int getGradeForSign() const;
	int getGradeForExecute() const;

	class GradeTooHighException : std::exception {
	public:
		virtual const char *thereIsAnIssue() {
			return "this grade is to higher";
		}
	};

	class GradeTooLowException : std::exception {
	public:
		virtual const char *thereIsAnIssue() {
			return "this grade is to lower";
		}
	};

	class DocuementNotSigned : std::exception {
	public:
		virtual const char *thereIsAnIssue() {
			return "The document is not signed";
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
