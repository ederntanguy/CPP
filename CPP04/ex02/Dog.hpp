#ifndef EX00_DOG_HPP
#define EX00_DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
public:
    Dog();
    Dog(const Dog &src);
    virtual ~Dog();

    Dog &operator=(const Dog &rhs);
    virtual void makeSound() const;
    void addAThing(const std::string& value);
    void showThings();

private:
    int _posBrainToChange;
    Brain *_brain;
};


#endif //EX00_DOG_HPP
