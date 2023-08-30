#ifndef CPP04_CURE_HPP
#define CPP04_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure &src);
    ~Cure();

    Cure &operator=(const Cure &rhs);

	AMateria *clone() const;
	void use(ICharacter& target);
};


#endif //CPP04_CURE_HPP
