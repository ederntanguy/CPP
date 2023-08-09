#ifndef CPP04_BRAIN_HPP
#define CPP04_BRAIN_HPP

#include <iostream>

class Brain {

public:
    Brain();
    Brain(const Brain &src);
    virtual ~Brain();
    Brain &operator=(const Brain &rhs);
    std::string idea[100];
};


#endif //CPP04_BRAIN_HPP
