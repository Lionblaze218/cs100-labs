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
                 visitor->visit_mult_begin(this);
             }
             else if (index == 1){
                 visitor->visit_mult_middle(this);
             }
             else if (index == 2){
                 visitor->visit_mult_end(this);
             }
         }
	~Mult(){
	delete value1;
	delete value2;
	}
    private:

	Base* value1;
	Base* value2;
};
#endif //__MULT_HPP__

