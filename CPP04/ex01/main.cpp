#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal *goodAnimal[20];
    for (int i = 0; i < 10; ++i) {
        goodAnimal[i] = new Cat();
    }
    for (int i = 10; i < 20; ++i) {
        goodAnimal[i] = new Dog();
    }
    static_cast<Cat *>(goodAnimal[0])->addAThing("fsdadf");
    static_cast<Cat *>(goodAnimal[0])->addAThing("hngbk");
    static_cast<Cat *>(goodAnimal[0])->addAThing("fsfdsdadf");
    static_cast<Cat *>(goodAnimal[0])->addAThing("fsdarrrrrrrrrrrrrrrrdf");
    static_cast<Cat *>(goodAnimal[0])->showThings();
    for (int i = 0; i < 20; ++i) {
        delete goodAnimal[i];
    }
    return 0;
}