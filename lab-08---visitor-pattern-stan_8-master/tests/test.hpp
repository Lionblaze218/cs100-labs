#ifndef __TEST_HPP__
#define __TEST_HPP__

#include <string>

#include "gtest/gtest.h"

#include "../iterator.hpp"
#include "../visitor.hpp"
#include "../visitorLatex.hpp"

#include "../src/op.hpp"
#include "../src/mult.hpp"
#include "../src/add.hpp"
#include "../src/sub.hpp"
#include "../src/div.hpp"
#include "../src/pow.hpp"


TEST(visitorTest, goodOutputI) {
	string test;
	VisitorLatex* visitor_ = new VisitorLatex();
	Base* one = new Op(1);
	Base* five = new Op(5);
	Base* zero = new Op(0);

	Base* sub = new Sub(five, zero);
	Base* add = new Add(one, sub);

	test = visitor_->PrintLaTeX(add);
	EXPECT_EQ(test, "${({1}+{({5}-{0})})}$" );

}

TEST(visitorTest, goodOutputII) {
	string test;
	VisitorLatex* visitor_ = new VisitorLatex();	
	Base* five = new Op(5);
	Base* two  = new Op(2);

	Base* pow = new Pow(five, two);
	
	test = visitor_->PrintLaTeX(pow);
	EXPECT_EQ(test, "${({5}^{2})}$");

}

TEST(visitorTest, goodOutputIII) {
        string test;
	VisitorLatex* visitor_ = new VisitorLatex();
        Base* two = new Op(2);
        Base* five = new Op(5);

        Base* mult = new Mult(two, five);

        test = visitor_->PrintLaTeX(mult);
        EXPECT_EQ(test, "${({2}\\cdot{5})}$");
}

TEST(visitorTest, goodOutputIV) {
        string test;
	VisitorLatex* visitor_ = new VisitorLatex();
        Base* two = new Op(2);
        Base* three = new Op(3);

        Base* div  = new Div(two, three);

        test = visitor_->PrintLaTeX(div);
        EXPECT_EQ(test, "${\\frac{2}{3}}$");
}

TEST(visitorTest, goodOutputV) {
        string test;
	VisitorLatex* visitor_ = new VisitorLatex();
        Base* two = new Op(2);
        Base* five = new Op(5);

        Base* mult = new Mult(two, five);
        Base* pow = new Pow(five, two);
        Base* div = new Div(mult, pow);

        test = visitor_->PrintLaTeX(div);
        EXPECT_EQ(test, "${\\frac{({2}\\cdot{5})}{({5}^{2})}}$");

}

TEST(visitorTest, zeroOutput) {
        string test;
        VisitorLatex* visitor_ = new VisitorLatex();
        Base* zero = new Op(0);
        Base* five = new Op(5);

        Base* pow = new Pow(five, zero);
	Base* add = new Add(pow, zero);

        test = visitor_->PrintLaTeX(add);
        EXPECT_EQ(test, "${({({5}^{0})}+{0})}$");

}

TEST(visitorTest, largeOutput) {
        string test;
        VisitorLatex* visitor_ = new VisitorLatex();
        Base* large = new Op(1000000);
        Base* three = new Op(3);

        Base* div = new Div(large, three);
        Base* add = new Add(div, large);

        test = visitor_->PrintLaTeX(add);
        EXPECT_EQ(test, "${({\\frac{1000000}{3}}+{1000000})}$");

}

TEST(visitorTest, negativeOutput) {
        string test;
        VisitorLatex* visitor_ = new VisitorLatex();
        Base* nOne = new Op(-1);
        Base* nThree = new Op(-3);

        Base* div = new Div(nOne, nThree);
        Base* sub = new Add(div, nOne);

        test = visitor_->PrintLaTeX(sub);
        EXPECT_EQ(test, "${({\\frac{-1}{-3}}+{-1})}$");

}

TEST(visitorTest, negativeLargeOutput) {
        string test;
        VisitorLatex* visitor_ = new VisitorLatex();
        Base* nLarge = new Op(-100000000);
        Base* nThree = new Op(-3);

        Base* div = new Div(nLarge, nThree);
        Base* pow = new Add(nLarge, div);

        test = visitor_->PrintLaTeX(pow);
        EXPECT_EQ(test, "${({-1e+08}+{\\frac{-1e+08}{-3}})}$");

}

TEST(visitorTest, oneOutput) {
        string test;
        VisitorLatex* visitor_ = new VisitorLatex();
        Base* five = new Op(5);

        test = visitor_->PrintLaTeX(five);
        EXPECT_EQ(test, "${5}$");

}

TEST(visitorTest, noOutput) {
        string test;
        VisitorLatex* visitor_ = new VisitorLatex();
        Base* five = new Op(0);

        test = visitor_->PrintLaTeX(five);
        EXPECT_EQ(test, "${0}$");

}


#endif
