#include <iostream>
#include <fstream>
#include <map>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please enter only one argument" << std::endl;
		return 0;
	}
	std::fstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile) {
		std::cerr << "The file : " << argv[1] << "doesn't exist" << std::endl;
		return 0;
	}
	std::fstream data;
	data.open("data.csv");
	if (!data) {
		std::cerr << "The file : data.csv doesn't exist" << std::endl;
		return 0;
	}
//	std::map<std::string, std::string> information;
}