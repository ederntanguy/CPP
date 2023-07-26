#include "Zombie.hpp"

Zombie *zombieHorde(int N, const std::string& name) {
	Zombie *zombies = new Zombie[N]; // Alloue un tableau de pointeurs sur Zombie

	for (int i = 0; i < N; ++i) {
		zombies[i] = Zombie(name);
	}

	return zombies;
}