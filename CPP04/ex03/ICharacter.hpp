#ifndef CPP04_ICHARACTER_HPP
#define CPP04_ICHARACTER_HPP


#include "AMateria.hpp"

class AMateria;

class ICharacter {
protected:
	AMateria *inventory[4];

public:
	inline virtual ~ICharacter() {};
    virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};


#endif //CPP04_ICHARACTER_HPP
