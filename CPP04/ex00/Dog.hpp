#ifndef EX00_DOG_HPP
#define EX00_DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
public:
    Dog();
    Dog(const Dog &src);
    virtual ~Dog();

    Dog &operator=(const Dog &rhs);
    virtual void makeSound() const;
};


#endif //EX00_DOG_HPP
