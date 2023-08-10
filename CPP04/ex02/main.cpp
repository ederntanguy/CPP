#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    AAnimal *goodAnimal[20];
//    AAnimal *goodAnimal[21];

    for (int i = 0; i < 10; ++i) {
        goodAnimal[i] = new Cat();
    }
    for (int i = 10; i < 20; ++i) {
        goodAnimal[i] = new Dog();
    }
//    goodAnimal[20] = new AAnimal();
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