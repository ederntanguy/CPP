#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "all.hpp"

class Character : public ICharacter{
public:
    Character();
	Character(std::string &name);
    Character(const Character &src);
    ~Character();

	const std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
    void use(int idx, ICharacter& target);
    Character &operator=(const Character rhs);
private:
	AMateria *inventory[4];
};


#endif //CPP04_CHARACTER_HPP
