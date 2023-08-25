#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP

#include "all.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &rhs);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	AMateria *materiaType[4];
};


#endif //CPP04_MATERIASOURCE_HPP
