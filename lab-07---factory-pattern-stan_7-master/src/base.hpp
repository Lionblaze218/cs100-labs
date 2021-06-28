#ifndef BASE_HPP
#define BASE_HPP

#include <string>

class Base {
    public:
       
        Base() {}

        virtual ~Base() {}

        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

#endif //BASE_HPP
