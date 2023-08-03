#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "wrong";
    std::cout << "creation du WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    *this = src;
    std::cout << "creation du WrongAnimal " << this->type << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "destruction du WrongAnimal " << this->type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
    this->type = rhs.type;
    return *this;
}

void WrongAnimal::makeSound() const{
    std::cout << "i'm nothing" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
