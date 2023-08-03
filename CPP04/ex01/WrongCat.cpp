#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()  {
    this->type = "WrongCat";
    std::cout << "creation d'un WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    *this = src;
    std::cout << "creation du WrongCat " << this->type << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "destruction du WrongCat " << this->type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
    this->type = rhs.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "meow'm meow fucking meow bro" << std::endl; // i'm a fucking cat bro
}