#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class Op : public Base {
    public:
        Op(double value) : Base(), value(value) { }
        virtual double evaluate() { return value; }

        virtual std::string stringify() {
		ostringstream ss;
		ss << setprecision(8) << noshowpoint << value;
		return ss.str();
	 }
     virtual int number_of_children(){
         return 0;
     }
     virtual Base* get_child(int i){
         return nullptr;
     }
    virtual void accept(Visitor* visitor, int index){
         visitor->visit_op(this);
    }

    ~Op() {
		delete value1;

	}
    private:
	double value;
    Base* value1;
};
#endif //__OP_HPP__
