#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria{
public:
    Ice();
    Ice(const Ice &src);
    ~Ice();

    Ice &operator=(const Ice &rhs);

};


#endif //CPP04_ICE_HPP
