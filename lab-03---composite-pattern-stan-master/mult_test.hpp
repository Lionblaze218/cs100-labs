#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Base* seven = new Op(7);
    Base* eight = new Op(8);
    Mult* test = new Mult(seven, eight);    
    EXPECT_EQ(test->evaluate(), 56);
}

TEST(MultTest, MultEvaluateZero) {
    Base* five = new Op(7);
    Base* zero = new Op(0);
    Mult* test = new Mult(five, zero);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNegative) {
    Base* seven = new Op(7);
    Base* nThree = new Op(-3);
    Mult* test = new Mult(seven, nThree);
    EXPECT_EQ(test->evaluate(), -21);
}

TEST(MultTest, MultEvaluateNonZeroFloat) {
    Base* three = new Op(3.5);
    Base* sixteen = new Op(16.2);
    Mult* test = new Mult(three, sixteen);
    double x = 3.5 * 16.2;
    EXPECT_EQ(test->evaluate(), x);
}


#endif //__MULT_TEST_HPP__

