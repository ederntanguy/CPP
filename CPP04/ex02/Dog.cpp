#include "Dog.hpp"


Dog::Dog() : AAnimal(), _posBrainToChange(0) {
    this->type = "Dog";
    this->_posBrainToChange = 0;
    std::cout << "creation d'un Dog" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src) {
    *this = src;
    this->_brain = src._brain;
    this->_posBrainToChange = src._posBrainToChange;
    std::cout << "creation du Dog " << this->type << std::endl;
}

Dog::~Dog() {
    std::cout << "destruction du Dog " << this->type << std::endl;
    delete this->_brain;
}

Dog &Dog::operator=(const Dog &rhs) {
    this->type = rhs.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "woof ruff grrr ruff doggo woof" << std::endl; // i'm a fucking dog bro
}

void Dog::addAThing(const std::string& value) {
    this->_brain->idea[this->_posBrainToChange % 100] = value;
}

void Dog::showThings() {
    int i = 0;
    while (i < 100 && i < _posBrainToChange)
    {
        std::cout << this->_brain->idea[i] << std::endl;
        i++;
    }
}
