#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat &src);
    virtual ~Cat();

    Cat &operator=(const Cat &rhs);
    virtual void makeSound() const;

};


#endif //EX00_CAT_HPP
