#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"

TEST(DivTest, DivEvaluateNonZero) {
    Base* fifty = new Op(50);
    Base* ten = new Op(10);
    Div* test = new Div(fifty, ten);    
    EXPECT_EQ(test->evaluate(), 5);
}

TEST(DivTest, DivEvaluateZero) {
    Base* zero = new Op(0);
    Base* five = new Op(5);
    Div* test = new Div(zero, five);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivEvaluateNegative) {
    Base* nine = new Op(9);
    Base* nThree = new Op(-3);
    Div* test = new Div(nine, nThree);
    EXPECT_EQ(test->evaluate(), -3);
}

TEST(DivTest, DivEvaluateNonZeroFloat) {
    Base* thirteen = new Op(13.24);
    Base* nine = new Op(9.9);
    Div* test = new Div(thirteen, nine);
    double x = 13.24 / 9.9;
    EXPECT_EQ(test->evaluate(), x);
}
//TEST(DivTest, DivEvaluateThrow) {
//    Base* five = new Op(5);
//    Base* zero = new Op(0);
//    Div* test = new Div(five, zero);
//    EXPECT_THROW(test->evaluate(), runtime_error);
//}


#endif //__Div_TEST_HPP__

