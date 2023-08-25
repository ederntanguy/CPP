#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &src);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &rhs);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};


#endif //CPP04_MATERIASOURCE_HPP
