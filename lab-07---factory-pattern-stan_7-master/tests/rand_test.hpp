#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "rand.hpp"

TEST(RandTest, RandEvaluateNonZero) {
    srand(0);
    Rand* test = new Rand();    
    EXPECT_GE(test->evaluate(), 0);
}
#endif //__MULT_TEST_HPP__

