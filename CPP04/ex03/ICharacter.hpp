#ifndef CPP04_ICHARACTER_HPP
#define CPP04_ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
protected:
	virtual AMateria clone();


public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif //CPP04_ICHARACTER_HPP