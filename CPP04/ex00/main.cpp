#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* goodAnimal = new Animal();
    const Animal* goodDog = new Dog();
    const Animal* goodCat = new Cat();
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << goodAnimal->getType() << " " << std::endl;
    std::cout << goodDog->getType() << " " << std::endl;
    std::cout << goodCat->getType() << " " << std::endl;
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    goodCat->makeSound();
    goodDog->makeSound();
    goodAnimal->makeSound();
    wrongAnimal->makeSound();
    wrongCat->makeSound();
    delete goodAnimal;
    delete goodDog;
    delete goodCat;
    delete wrongAnimal;
    delete wrongCat;
    return 0;
}