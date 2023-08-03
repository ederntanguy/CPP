#ifndef EX00_WRONGCAT_HPP
#define EX00_WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal{
public:
    WrongCat();
    WrongCat(const WrongCat &src);
    virtual ~WrongCat();

    WrongCat &operator=(const WrongCat &rhs);
    void makeSound() const;


};


#endif //EX00_WRONGCAT_HPP
