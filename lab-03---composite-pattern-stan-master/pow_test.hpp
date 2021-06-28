#ifndef _POW_TEST_HPP
#define _POW_TEST_HPP

#include "gtest/gtest.h"
#include "pow.hpp"
#include "op.hpp"


TEST(powTest, powZeros) {
	Base* ten = new Op(10);
	Base* zero = new Op(0);

	Pow* test = new Pow(ten, zero);
	EXPECT_EQ(test->evaluate(), 1);

}

TEST(powTest, powIdentity) {
	Base* ten = new Op(10);
	Base* one = new Op(1);

	Pow* test = new Pow(ten, one);
	EXPECT_EQ(test->evaluate(), 10);

}

TEST(powTest, powNegative) {
	Base* two = new Op(2);
	Base* negOne = new Op(-1);

	Pow* test = new Pow(two, negOne);
	EXPECT_EQ (test->evaluate(), 0.5);

}

TEST(powTest, subTwoNegative) {
	Base* negTwo = new Op(-2);
	Base* negOne = new Op(-1);

	Pow* test = new Pow(negTwo, negOne);
	EXPECT_EQ (test->evaluate(), -0.5);

}

TEST(powTest, powNegativePos) {
	Base* negTwo = new Op(-2);
	Base* one = new Op(1);

	Pow* test = new Pow(negTwo, one);
	EXPECT_EQ(test->evaluate(), -2);

}

#endif

