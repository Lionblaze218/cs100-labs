#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "iostream"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include<time.h>

using namespace std;

class Rand : public Base {
    public:
        Rand() : Base() {
	srand(time(0));
	value = rand()%100;
	 }
        virtual double evaluate() {
            return value;
        }
        virtual string stringify() {
		ostringstream ss;
		ss << setprecision(8) << noshowpoint << value;
		return ss.str();
	 }
	private:
	double value;
};
#endif //__RAND_HPP__o
