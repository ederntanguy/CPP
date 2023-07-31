#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap toutou("toutou");

	ClapTrap inspecteurGadget("inpercteur gadget");

	toutou.attack("renard");
	toutou.takeDamage(20);
	toutou.attack("renard");
	toutou.takeDamage(40);

	ScavTrap wouaf = toutou;

	wouaf.guardGate();
	wouaf.beRepaired(3);
	wouaf.takeDamage(90);
	wouaf.attack("renard");
	wouaf.beRepaired(50);
	wouaf.takeDamage(2);
	wouaf.guardGate();

	std::cout << std::endl;

	inspecteurGadget.beRepaired(10000);
	inspecteurGadget.attack("eclaire en chocolat");
	inspecteurGadget.takeDamage(1000);
	inspecteurGadget.takeDamage(9000);
	inspecteurGadget.takeDamage(100000000);
	inspecteurGadget.takeDamage(1000);
	inspecteurGadget.attack("eclaire en chocolat");


	std::cout << std::endl;
	FragTrap miaou("miaou");

	miaou.highFivesGuys();

	for (int i = 0; i < 93; ++i) {
		miaou.beRepaired(10);
	}
	miaou.highFivesGuys();
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.beRepaired(12);
	miaou.highFivesGuys();
	miaou.beRepaired(12);
	miaou.attack("le vilain petit canard");


	return 0;
}