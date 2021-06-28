#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "iostream"
#include <stdlib.h>
#include <string>
#include <stdexcept>

using namespace std;

class Div : public Base {
    public:
        Div(Base* value1, Base* value2) : Base(), value1(value1), value2(value2){ }
        virtual double evaluate() {
	if(value2->evaluate() == 0){
	    try{
		throw runtime_error("Cannot be divisible by 0");
	    }
	    catch(runtime_error const& e){
		cout << "Caught a runtime_error exception: " << e.what() << endl;
	    }
	}
            return (value1->evaluate() / value2->evaluate());
        }
        virtual string stringify() {
		string ss;
		ss = "(" + value1->stringify() + "/" + value2->stringify() + ")";
		return ss;
         }
	~Div(){
	delete value1;
	delete value2;
	}
    private:
	Base* value1;
	Base* value2;
};
#endif //__DIV_HPP__o
