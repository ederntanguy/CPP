#include "Brain.hpp"

Brain::Brain() {
    std::cout << "creation d'un Brain" << std::endl;
}

Brain::Brain(const Brain &src) {
    *this = src;
    std::cout << "creation d'un Brain" << std::endl;
}

Brain::~Brain() {
    std::cout << "destruction d'un Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
    *(this->idea) = *(rhs.idea);
    return *this;
}
