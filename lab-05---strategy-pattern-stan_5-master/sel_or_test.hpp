#ifndef __SEL_OR_TEST_HPP
#define __SEL_OR_TEST_HPP

#include "gtest/gtest.h"

#include "spreadsheet.hpp"

TEST(SelOrTest, BasicOrTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"Major","chess"), new Select_Contains(&sheet,"Age","-2")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person2 Last2 -2 Basket Weaving \nPerson3 Last3 0 chess \n");
}

TEST(SelOrTest, BasicOrEmptyTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"Last","last"), new Select_Not(new Select_Contains(&sheet,"Major","Philosophy"))));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}
TEST(SelOrTest, BasicOrTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        EXPECT_THROW(sheet.set_selection(new Select_Or(new Select_Contains(&sheet,"test","Last"),new Select_Or(new Select_Contains(&sheet,"test","Last"), new Select_Contains(&sheet,"Last","Last")))),runtime_error);
    	}
        
#endif //__SEL_OR_TEST_HPP
        
