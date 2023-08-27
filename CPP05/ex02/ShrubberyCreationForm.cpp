#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const std::string &target) :
													AForm(name, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	this->_sign = rhs.getSign();
	this->_gradeForExecute = rhs.getGradeForExecute();
	this->_gradeForSign = rhs.getGradeForSign();
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->_sign)
	{
		std::cout << "The document is not signed" << std::endl;
		return;
	}
	try {
		if (static_cast<int>(executor.getGrade()) > this->_gradeForExecute)
			throw ShrubberyCreationForm::GradeTooLowException();
		std::string shrubberyFile = this->_target + "_shrubbery";
		std::ofstream outputFile(shrubberyFile.c_str());
		if (outputFile.is_open())
		{
			outputFile << "                     .o00o";
			outputFile << "                   o000000oo";
			outputFile << "                  00000000000o";
			outputFile << "                 00000000000000";
			outputFile << "              oooooo  00000000  o88o";
			outputFile << "           ooOOOOOOOoo  ```''  888888";
			outputFile << "         OOOOOOOOOOOO'.qQQQQq. `8888'";
			outputFile << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'";
			outputFile << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q";
			outputFile << "         OOOOOOOOO QQQQQQQQQQ/ /QQ";
			outputFile << "           OOOOOOOOO `QQQQQQ/ /QQ'";
			outputFile << "             OO:F_P:O `QQQ/  /Q'";
			outputFile << "                \\\\. \\ |  // |";
			outputFile << "                d\\ \\\\\\|_////";
			outputFile << "                qP| \\\\ _' `|Ob";
			outputFile << "                   \\  / \\  \\Op";
			outputFile << "                   |  | O| |";
			outputFile << "           _       /\\. \\_/ /\\";
			outputFile << "            `---__/|_\\\\   //|  __";
			outputFile << "                  `-'  `-'`-'-'";
		}
		else {
			std::cout << "can't open or creat " << shrubberyFile << " for draw a amaizing shrubbery" << std::endl;
		}
	}
	catch (ShrubberyCreationForm::GradeTooLowException &e) {
		std::cout << "the Bureaucrat " << executor.getName() << " can't execute " << this->_name << std::endl;
	}
}
