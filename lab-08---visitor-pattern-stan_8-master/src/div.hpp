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
		throw runtime_error("cannot be divisible by 0");
	    }
	    catch(runtime_error const& e){
		cout << "caught a runtime_error exception: " << e.what() << endl;
	    }
	}
            return (value1->evaluate() / value2->evaluate());
        }
        virtual string stringify() {
		string ss;
		ss = "(" + value1->stringify() + "/" + value2->stringify() + ")";
		return ss;
         }
	


	 virtual int number_of_children(){
             return 2;
         }
         virtual Base* get_child(int i){
             if (i == 0){
                 return value1;
             }
             else if (i == 1){
                 return value2;
             }
             else{
                 return nullptr;
             }
         }
         virtual void accept(Visitor* visitor, int index){
             if (index == 0){
                 visitor->visit_div_begin(this);
             }
             else if (index == 1){
                 visitor->visit_div_middle(this);
             }
             else if (index == 2){
                 visitor->visit_div_end(this);
             }
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
