#include "DiamondTrap.hpp"

int main() {
	DiamondTrap test("laya");

	test.attack("fd");
	test.whoAmI();
	test.whoAmI();
	test.highFivesGuys();
	test.guardGate();
	test.takeDamage(20);
	test.beRepaired(50);
	return 0;
}