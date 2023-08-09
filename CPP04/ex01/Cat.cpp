#include "Cat.hpp"

Cat::Cat() : Animal()  {
    this->type = "Cat";
    this->_posBrainToChange = 0;
    this->_brain = new Brain();
    std::cout << "creation d'un Cat" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), _posBrainToChange(0)  {
    *this = src;
    this->_brain = src._brain;
    this->_posBrainToChange = src._posBrainToChange;
    std::cout << "creation du Cat " << this->type << std::endl;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "destruction du Cat " << this->type << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
    this->type = rhs.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "meow'm meow fucking meow bro" << std::endl; // i'm a fucking cat bro
}

void Cat::addAThing(const std::string& value) {
    this->_brain->idea[this->_posBrainToChange % 100] = value;
    this->_posBrainToChange++;
}

void Cat::showThings() {
    int i = 0;
    while (i < 100 && i < _posBrainToChange)
    {
        std::cout << this->_brain->idea[i] << std::endl;
        i++;
    }
}
