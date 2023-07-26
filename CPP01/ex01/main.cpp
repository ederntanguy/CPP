#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
	int N = 10;
	Zombie *zombie = zombieHorde(N, "etanguyyyyyyyyyyy");
	for (int i = 0; i < N; ++i) {
		zombie[i].announce();
	}
	delete[] zombie;
	return 0;
}