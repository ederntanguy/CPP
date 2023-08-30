#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP


#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
	explicit AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria(const AMateria &src);
	std::string const &getType() const; //Returns the materia type
	virtual AMateria *clone() const = 0;
    virtual void use(ICharacter& target);

	AMateria &operator=(const AMateria &rhs);

protected:
	std::string _type;
};


#endif //CPP04_AMATERIA_HPP
