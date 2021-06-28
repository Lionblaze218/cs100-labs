#ifndef _ADD_TEST_HPP
#define _ADD_TEST_HPP

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"


TEST(addTest, addZeros) {
	Base* zero_one = new Op(0);
	Base* zero_two = new Op(0);

	Add* test = new Add(zero_one, zero_two);
	EXPECT_EQ(test->evaluate(), 0);

}

TEST(addTest, addIdentity) {
	Base* ten = new Op(10);
	Base* zero = new Op(0);

	Add* test = new Add(ten, zero);
	EXPECT_EQ (test->evaluate(), 10);

}

TEST(addTest, addNegative) {
	Base* ten = new Op(10);
	Base* five = new Op(-5);

	Add* test = new Add(ten, five);
	EXPECT_EQ (test->evaluate(), 5);

}

#endif

