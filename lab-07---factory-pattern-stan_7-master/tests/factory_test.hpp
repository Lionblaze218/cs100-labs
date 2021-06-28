#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"

#include "../src/factory.hpp"
#include "../src/op.hpp"
#include "../src/mult.hpp"
#include "../src/add.hpp"
#include "../src/sub.hpp"
#include "../src/div.hpp"
#include "../src/pow.hpp"


TEST(FactoryTest, BasicTest1){
	factory test;
	char *args[] = {"3", "+", "4"};
	Base *op = test.parse(args, 3);
	EXPECT_DOUBLE_EQ(op->evaluate(), 7);
}

TEST(FactoryTest, BasicTest2){
        factory test;
        char *args[] = {"3", "-", "8"};
        Base *op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), -5);
}

TEST(FactoryTest, BasicTest3){
        factory test;
        char *args[] = {"3", "-", "8", "*", "2"};
        Base *op = test.parse(args, 5);
        EXPECT_DOUBLE_EQ(op->evaluate(), -10);
}

TEST(FactoryTest, BasicTest4){
        factory test;
        char *args[] = {"3"};
        Base *op = test.parse(args, 1);
        EXPECT_DOUBLE_EQ(op->evaluate(), 3);
}


TEST(FactoryTest, PowTest){
        factory test;
        char *args[] = {"8", "\*\*", "3"};
        Base *op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 512);
}

TEST(FactoryTest, DivTest){
        factory test;
        char *args[] = {"30", "/", "6"};
        Base *op = test.parse(args, 3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 5);
}

//more tests

TEST(FactoryTest, SubFirstTest) {
	factory test;
	char *args[] = {"-", "4", "2"};
	Base *op = test.parse(args,3);
	EXPECT_EQ(op, nullptr);

}

TEST(FactoryTest, AddFirstTest) {
	factory test;
        char *args[] = {"+", "4", "2"};
        Base *op = test.parse(args,3);
        EXPECT_EQ(op, nullptr);

}

TEST(FactoryTest, MultFirstTest) {
        factory test;
        char *args[] = {"*", "4", "2"};
        Base *op = test.parse(args,3);
        EXPECT_EQ(op, nullptr);

}

TEST(FactoryTest, DivFirstTest) {
        factory test;
        char *args[] = {"/", "4", "2"};
        Base *op = test.parse(args,3);
        EXPECT_EQ(op, nullptr);

}

TEST(FactoryTest, PowFirstTest) {
        factory test;
        char *args[] = {"**", "4", "2"};
        Base *op = test.parse(args,3);
        EXPECT_EQ(op, nullptr);

}


TEST(FactoryTest, LetterFirst) {
	factory test;
	char *args[] = {"x", "+", "4"};
	Base *op = test.parse(args,3);
	EXPECT_EQ(op, nullptr);

}

TEST(FactoryTest, LetterTest) {
	factory test;
	char *args[] = {"4", "+", "x"};
	Base *op = test.parse(args,3);
	EXPECT_EQ(op, nullptr);

}

TEST(FactoryTest, ComplicatedTest) {
        factory test;
        char *args[] = {"4", "+", "5", "/" , "9", "*", "1500", "-", "1"};
        Base *op = test.parse(args,9);
        EXPECT_DOUBLE_EQ(op->evaluate(), 1499);

}

TEST(FactoryTest, ComplicatedTest2) {
        factory test;
        char *args[] = {"0", "+", "0", "/" , "1", "*", "100000", "-", "1"};
        Base *op = test.parse(args,9);
        EXPECT_DOUBLE_EQ(op->evaluate(), -1);

}

TEST(FactoryTest, ComplicatedTest3) {
        factory test;
        char *args[] = {"0.1", "*", "3"};
        Base *op = test.parse(args,3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 0.3);

}

TEST(FactoryTest, ComplicatedTest4) {
        factory test;
        char *args[] = {"0.4", "+", "0.5"};
        Base *op = test.parse(args,3);
        EXPECT_DOUBLE_EQ(op->evaluate(), 0.9);

}


#endif //FACTORY
