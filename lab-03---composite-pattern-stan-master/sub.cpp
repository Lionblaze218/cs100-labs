#include "sub.hpp"
#include <string>

using namespace std;

Sub::Sub(double num1, double num2) {
	this->num1 = num1;
	this->num2 = num2;
}

Sub::~Sub() {}

double Sub::evaluate() {
	return (num1 - num2);
}

string Sub::stringify() {
	string expression;
	expression = "(" + to_string(num1) + "-" + to_string(num2) + ")";
	return expression;

}
