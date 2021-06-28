#include <iostream>
#include "base.hpp"
#include "factory.hpp"

using namespace std;

int main (int argc, char* argv[]) {
    factory equation;
    char *argv_[argc-1];
    for(int i = 1; i < argc; i++){
        argv_[i-1] = argv[i];
    }
    Base *op = equation.parse(argv_, argc-1);
    cout << op->evaluate() << endl;
    delete op;

	return 0;

}
