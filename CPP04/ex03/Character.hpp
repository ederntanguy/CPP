#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter{
public:
    Character();
    Character(const Character &src);
    ~Character();

    std::string const & getName();
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    Character &operator=(const Character rhs);
};


#endif //CPP04_CHARACTER_HPP
