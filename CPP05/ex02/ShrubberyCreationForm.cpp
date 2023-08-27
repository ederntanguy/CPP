#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
													AForm(target, 145, 137), _target(target) {}

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
			throw GradeTooLowException();
		std::string shrubberyFile = this->_target + "_shrubbery";
		std::ofstream outputFile(shrubberyFile.c_str());
		if (outputFile.is_open())
		{
			outputFile << "                     .o00o\n";
			outputFile << "                   o000000oo\n";
			outputFile << "                  00000000000o\n";
			outputFile << "                 00000000000000\n";
			outputFile << "              oooooo  00000000  o88o\n";
			outputFile << "           ooOOOOOOOoo  ```''  888888\n";
			outputFile << "         OOOOOOOOOOOO'.qQQQQq. `8888'\n";
			outputFile << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n";
			outputFile << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n";
			outputFile << "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n";
			outputFile << "           OOOOOOOOO `QQQQQQ/ /QQ'\n";
			outputFile << "             OO:F_P:O `QQQ/  /Q'\n";
			outputFile << "                \\\\. \\ |  // |\n";
			outputFile << "                d\\ \\\\\\|_////\n";
			outputFile << "                qP| \\\\ _' `|Ob\n";
			outputFile << "                   \\  / \\  \\Op\n";
			outputFile << "                   |  | O| |\n";
			outputFile << "           _       /\\. \\_/ /\\\n";
			outputFile << "            `---__/|_\\\\   //|  __\n";
			outputFile << "                  `-'  `-'`-'-'";
		}
		else {
			std::cout << "can't open or creat " << shrubberyFile << " for draw a amazing shrubbery" << std::endl;
		}
	}
	catch (ShrubberyCreationForm::GradeTooLowException &e) {
		std::cout << "the Bureaucrat " << executor.getName() << " can't execute " << this->_name << std::endl;
	}
}
