#ifndef __MOCK_HPP__
#define __MOCK_HPP__

#include "base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class SevenOpMock: public Base {
    public:
        SevenOpMock() { }

        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
}

class NegFiveOpMock: public Base {
    public:
        NegFiveOpMock() { }

        virtual double evaluate() { return -5.0; }
        virtual string stringify() { return "-5.0"; }
}

class ZeroOpMock: public Base {
    public:
        ZeroOpMock() { }

        virtual double evaluate() { return 0; }
        virtual string stringify() { return "0"; }
}
};
#endif
