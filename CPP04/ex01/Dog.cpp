#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "creation d'un Dog" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    *this = src;
    std::cout << "creation du Dog " << this->type << std::endl;
}

Dog::~Dog() {
    std::cout << "destruction du Dog " << this->type << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
    this->type = rhs.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "woof ruff grrr ruff doggo woof" << std::endl; // i'm a fucking dog bro
}
