#ifndef __SEL_NOT_TEST_HPP
#define __SEL_NOT_TEST_HPP

#include "gtest/gtest.h"

#include "spreadsheet.hpp"

TEST(SelNotTest, BasicNotTest){
	Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
	sheet.add_row({"Person1","Last1","10000","Philosophy"});
	sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
	sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"Major","chess")));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \nPerson2 Last2 -2 Basket Weaving \n");
}

TEST(SelNotTest, BasicNotTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"Major","Chess")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \nPerson2 Last2 -2 Basket Weaving \nPerson3 Last3 0 chess \n");
}

TEST(SelNotTest, BasicNotTest3){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"Major","Basket")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \nPerson3 Last3 0 chess \n");
}

TEST(SelNotTest, BasicFailTest3){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"First","P")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}

TEST(SelNotTest, NumFindTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"Age","0")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person2 Last2 -2 Basket Weaving \n");
}

TEST(SelNotTest, NumFindTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"Age","100")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person2 Last2 -2 Basket Weaving \nPerson3 Last3 0 chess \n");
}

TEST(SelNotTest, NotEmptyTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Not(new Select_Contains(&sheet,"Age","")));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}


#endif //__SEL_NOT_TEST_HPP
