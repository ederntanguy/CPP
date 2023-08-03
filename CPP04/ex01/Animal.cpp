#include "Animal.hpp"

Animal::Animal() {
    this->type = "";
    std::cout << "creation d'un Animal" << std::endl;
}

Animal::Animal(const Animal &src) {
    *this = src;
    std::cout << "creation de l'Animal " << this->type << std::endl;
}

Animal::~Animal() {
    std::cout << "destruction de l'Animal " << this->type << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
    this->type = rhs.type;
    return *this;
}

void Animal::makeSound() const{
    std::cout << "i'm nothing" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
