#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "../iterator.hpp"
#include "../visitorLatex.hpp"

using namespace std;

int main () {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* add = new Add(three, seven);
    Base* add2 = new Add(add, four);

    VisitorLatex* visitor_ = new VisitorLatex();

    cout << visitor_->PrintLaTeX(add2) << endl;

    delete visitor_;
    
	return 0;

}

