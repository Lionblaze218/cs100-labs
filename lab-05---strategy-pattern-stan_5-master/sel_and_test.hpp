#ifndef __SEL_NOT_TEST_HPP
#define __SEL_NOT_TEST_HPP

#include "gtest/gtest.h"

#include "spreadsheet.hpp"

TEST(SelAndTest, BasicAndTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_And(new Select_Contains(&sheet,"Major","chess"), new Select_Contains(&sheet,"Age","0")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person3 Last3 0 chess \n");
}

TEST(SelAndTest, BasicAndEmptyTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.set_selection(new Select_And(new Select_Contains(&sheet,"Last","Last"), new Select_Not(new Select_Contains(&sheet,"Major","Philosophy"))));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}
                                           
TEST(SelAndTest, BasicAndTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        EXPECT_THROW(sheet.set_selection(new Select_And(new Select_Contains(&sheet,"test","Last"),new Select_And(new Select_Contains(&sheet,"test","Last"), new Select_Contains(&sheet,"Last","Last")))),runtime_error);
        //std::stringstream out;
        //sheet.print_selection(out);
}

#endif //__SEL_AND_TEST_HPP
