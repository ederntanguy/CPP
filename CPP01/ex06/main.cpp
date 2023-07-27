#include "Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}

	std::string str(argv[1]);
	if (str != "DEBUG" && str != "INFO" && str != "WARNING" && str != "ERROR")
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	Harl harl;

	harl.complain(str);
}