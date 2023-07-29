#include "ClapTrap.hpp"

int main() {
	ClapTrap toutou("toutou");
	ClapTrap miaou("miaou");


	toutou.attack("renard");
	toutou.takeDamage(2);
	toutou.attack("renard");
	toutou.takeDamage(2);
	toutou.beRepaired(3);
	toutou.takeDamage(90);
	toutou.attack("renard");
	toutou.beRepaired(50);
	toutou.takeDamage(2);

	std::cout << std::endl;

	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.attack("le vilain petit canard");
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.beRepaired(12);
	miaou.attack("le vilain petit canard");
	return 0;
}