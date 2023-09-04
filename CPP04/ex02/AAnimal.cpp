#include "AAnimal.hpp"

AAnimal::AAnimal() {
    this->type = "";
    std::cout << "creation d'un Animal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
    *this = src;
    std::cout << "creation de l'Animal " << this->type << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "destruction de l'Animal " << this->type << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
    this->type = rhs.type;
    return *this;
}

std::string AAnimal::getType() const {
    return this->type;
}
