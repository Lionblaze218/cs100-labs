#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "iostream"
#include <stdlib.h>
#include <string>

using namespace std;

class Mult : public Base {
    public:

        Mult(Base* value1, Base* value2) : Base(), value1(value1), value2(value2){ }
        virtual double evaluate() {
            return (value1->evaluate() * value2->evaluate());
        }
        virtual string stringify() {
		string ss;
		ss = "(" + value1->stringify() + "*" + value2->stringify() + ")";
		return ss;
         }
    private:

	Base* value1;
	Base* value2;
};
#endif //__MULT_HPP__

