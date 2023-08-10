#ifndef EX00_WRONGANIMAL_HPP
#define EX00_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    virtual ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &rhs);

    void makeSound() const;
    std::string getType() const;

protected:
    std::string type;

};


#endif //EX00_WRONGANIMAL_HPP
