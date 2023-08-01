#include "DiamondTrap.hpp"

int main() {
	DiamondTrap chien1("laya");


	std::cout << "\n\nchien1" << std::endl;
	chien1.attack("fd");
	chien1.whoAmI();
	chien1.highFivesGuys();
	chien1.guardGate();
	chien1.takeDamage(20);
	chien1.beRepaired(50);

	DiamondTrap chien1bis;
	chien1bis = chien1;
	DiamondTrap chien1bisbis(chien1bis);

	std::cout << "\n\nchien1bis" << std::endl;
	chien1bis.attack("fd");
	chien1bis.whoAmI();
	chien1bis.highFivesGuys();
	chien1bis.guardGate();
	chien1bis.takeDamage(20);
	chien1bis.beRepaired(50);

	std::cout << "\n\nchien1bisbis" << std::endl;
	chien1bisbis.attack("fd");
	chien1bisbis.whoAmI();
	chien1bisbis.highFivesGuys();
	chien1bisbis.guardGate();
	chien1bisbis.takeDamage(20);
	chien1bisbis.beRepaired(50);

	return 0;
}