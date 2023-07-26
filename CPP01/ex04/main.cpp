#include "replace.hpp"

void replace(std::string &allContent, std::string oldStr, std::string newStr) {
	int lengthOldStr = oldStr.length();
//	int lengthNewStr = newStr.length();
	size_t index = allContent.find(oldStr);
	while (index != std::string::npos)
	{
		allContent = allContent.substr(0, index) + allContent.substr(index + lengthOldStr, allContent.length());
		allContent.insert(index, newStr);
		index = allContent.find(oldStr);
	}
}

int main(int argc, char **argv) {
	std::string replaceFile = std::string(argv[1]) + ".replace";
	if (argc != 4)
	{
		std::cout << "Invalide Number of Parametres" << std::endl;
		return 0;
	}

	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open())
	{
		std::string allContent;
		std::string line;
		while (std::getline(inputFile, line))
			allContent += line + "\n";
		replace(allContent, argv[2], argv[3]);
		std::ofstream outputFile(replaceFile.c_str());
		if (outputFile.is_open())
		{
			std::cout << allContent << std::endl;
			outputFile << allContent;
		} else {
			std::cout << "Can't open or creat the new file" << std::endl;
			return 0;
		}
	}
	else
	{
		std::cout << "This file doesn't exist" << std::endl;
		return 0;
	}
	return 0;
}