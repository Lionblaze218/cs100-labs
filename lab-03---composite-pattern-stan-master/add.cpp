#include "add.hpp"
#include <string>

using namespace std;

Add::Add(double num1, double num2) {
	this->num1 = num1;
	this->num2 = num2;
}

Add::~Add() {}

double Add::evaluate() {
	return num1 + num2;
}

string Add::stringify() {
	string expression;
	expression = "(" + to_string(num1) + "+" + to_string(num2) + ")";
	return expression;
}
