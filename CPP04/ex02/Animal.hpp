#ifndef EX00_ANIMAL_HPP
#define EX00_ANIMAL_HPP

#include <iostream>

class AAnimal {

public:
    AAnimal();
    AAnimal(const AAnimal &src);
    virtual ~AAnimal();

    AAnimal &operator=(const AAnimal &rhs);

    virtual void makeSound() const = 0;
    std::string getType() const;

protected:
    std::string type;

};


#endif //EX00_ANIMAL_HPP
