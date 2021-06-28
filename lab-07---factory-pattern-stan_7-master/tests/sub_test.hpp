#ifndef _SUB_TEST_HPP
#define _SUB_TEST_HPP

#include "gtest/gtest.h"
#include "sub.hpp"
#include "op.hpp"


TEST(subTest, subZeros) {
	Base* zero_one = new Op(0);
	Base* zero_two = new Op(0);

	Sub* test = new Sub(zero_one, zero_two);
	EXPECT_EQ (test->evaluate(), 0);

}

TEST(subTest, subIdentity) {
	Base* ten = new Op(10);
	Base* zero = new Op(0);

	Sub* test = new Sub(ten, zero);
	EXPECT_EQ (test->evaluate(), 10);

}

TEST(subTest, subNegative) {
	Base* ten = new Op(10);
	Base* negFive = new Op(-5);

	Sub* test = new Sub(ten, negFive);
	EXPECT_EQ (test->evaluate(), 15);

}

TEST(subTest, subTwoNegative) {
	Base* negTen = new Op(-10);
	Base* negFive = new Op(-5);

	Sub* test = new Sub(negTen, negFive);
	EXPECT_EQ (test->evaluate(), -5);

}

TEST(subTest, subNegativePos) {
	Base* negTen = new Op(-10);
	Base* five = new Op(5);

	Sub* test = new Sub(negTen, five);
	EXPECT_EQ (test->evaluate(), -15);

}


#endif

