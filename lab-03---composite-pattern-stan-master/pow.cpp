#include "Pow.hpp"
#include <string>
#include <math.h>

using namespace std;

Pow::Pow(double num1, double num2) {
	this->num1 = num1;
	this->num2 = num2;
}

Pow::~Pow() {}

double Pow::evaluate() {
	return pow(num1,num2);
}

string Pow::stringify() {
	string expression;
	expression = "(" + to_string(num1) + "**" + to_string(num2) + ")";
	return expression;

}
