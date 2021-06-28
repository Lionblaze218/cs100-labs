#include "gtest/gtest.h"

#include "spreadsheet.hpp"
#include "select.hpp"

#include "sel_or_test.hpp"
#include "sel_and_test.hpp"
#include "print_test.hpp"
#include "sel_con_test.hpp"
#include "sel_not_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
