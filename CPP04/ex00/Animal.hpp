#ifndef EX00_ANIMAL_HPP
#define EX00_ANIMAL_HPP

#include <iostream>

class Animal {

public:
    Animal();
    Animal(const Animal &src);
    virtual ~Animal();

    Animal &operator=(const Animal &rhs);

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type;

};


#endif //EX00_ANIMAL_HPP
