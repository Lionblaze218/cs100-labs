#include "gtest/gtest.h"

#include "../src/base.hpp"
#include "factory_test.hpp"
//#include "factory_test2.hpp"
//#include "op_test.hpp"
//#include "div_test.hpp"
//#include "mult_test.hpp"
//#include "add_test.hpp"
//#include "sub_test.hpp"
//#include "pow_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
