#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int main(void)
{
	Zombie *zombie1 = newZombie("etanguyyyyyyyyyyy");
	randomChump("jeSuisUnVilainZombie");

	zombie1->announce();
	delete zombie1;
	return 0;
}