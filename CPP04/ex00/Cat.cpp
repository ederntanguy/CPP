#include "Cat.hpp"

Cat::Cat() : Animal()  {
    this->type = "Cat";
    std::cout << "creation d'un Cat" << std::endl;
}

Cat::Cat(const Cat &src) : Animal() {
    *this = src;
    std::cout << "creation du Cat " << this->type << std::endl;
}

Cat::~Cat() {
    std::cout << "destruction du Cat " << this->type << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    this->type = rhs.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow'm meow fucking meow bro" << std::endl; // i'm a fucking cat bro
}
