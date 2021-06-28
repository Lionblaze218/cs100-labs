#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>
#include "iostream"
#include <stdlib.h>
#include <string>

using namespace std;

class Pow : public Base {
public:
    Pow(Base* value1, Base* value2) : Base(), value1(value1), value2(value2) { }
    virtual double evaluate() {
        return pow(value1->evaluate(),value2->evaluate());
    }
    virtual string stringify() {
        string ss;
        ss = "(" + (value1->stringify()) + "**" + (value2->stringify()) + ")";
        return ss;
    }
    ~Pow(){
	delete value1;
	delete value2;
	}

private:
    Base* value1;
    Base* value2;
};
#endif //__POW_HPP__

