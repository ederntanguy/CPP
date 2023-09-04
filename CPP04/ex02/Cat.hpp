#ifndef EX00_CAT_HPP
#define EX00_CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{

public:
    Cat();
    Cat(const Cat &src);
    virtual ~Cat();

    Cat &operator=(const Cat &rhs);
    virtual void makeSound() const;
    void addAThing(const std::string& value);
    void showThings();

private:
    int _posBrainToChange;
    Brain *_brain;

};


#endif //EX00_CAT_HPP
