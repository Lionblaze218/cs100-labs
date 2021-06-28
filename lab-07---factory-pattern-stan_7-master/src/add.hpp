#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "iostream"
#include <stdlib.h>
#include <string>

using namespace std;

class Add : public Base {
public:
    Add(Base* value1, Base* value2) : Base(), value1(value1), value2(value2) { }
    virtual double evaluate() {
        return (value1->evaluate() + value2->evaluate());
    }
    virtual string stringify() {
        string ss;
        ss = "(" + (value1->stringify()) + "+" + (value2->stringify()) + ")";
        return ss;
    }
    ~Add(){
	delete value1;
	delete value2;
    }
private:
    Base* value1;
    Base* value2;
};
#endif //__ADD_HPP__

