#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter{
public:
    Character();
	Character(const std::string &name);
    Character(const Character &src);
    ~Character();

	const std::string &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
    void use(int idx, ICharacter& target);

	Character &operator=(const Character rhs);
private:
	std::string _name;
};


#endif //CPP04_CHARACTER_HPP
