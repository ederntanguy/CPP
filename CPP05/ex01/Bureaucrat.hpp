#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP

#include "all.hpp"

class Form;

class Bureaucrat {
public:

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

	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &formulaire);

private:
	const std::string _name;
	unsigned int _grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i);


#endif //CPP05_BUREAUCRAT_HPP
