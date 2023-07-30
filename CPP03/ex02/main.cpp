#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap toutou("toutou");
	ClapTrap inspecteurGadget("inpercteur gadget");

	toutou.attack("renard");
	toutou.takeDamage(20);
	toutou.attack("renard");
	toutou.takeDamage(40);
	toutou.beRepaired(3);
	toutou.takeDamage(90);
	toutou.attack("renard");
	toutou.beRepaired(50);
	toutou.takeDamage(2);
	toutou.guardGate();

	std::cout << std::endl;

	inspecteurGadget.beRepaired(10000);
	inspecteurGadget.takeDamage(1000);
	inspecteurGadget.takeDamage(9000);
	inspecteurGadget.takeDamage(100000000);
	inspecteurGadget.takeDamage(1000);
	inspecteurGadget.attack("eclaire en chocolat");


	std::cout << std::endl;
	ScavTrap miaou("miaou");

	miaou.guardGate();
	for (int i = 0; i < 48; ++i) {
		miaou.attack("le vilain petit canard");
	}

	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.attack("le vilain petit canard");


	return 0;
}