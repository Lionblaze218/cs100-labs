#ifndef __SEL_CON_TEST_HPP
#define __SEL_CON_TEST_HPP

#include "gtest/gtest.h"

#include "spreadsheet.hpp"

TEST(SelConTest, BasicTest){
	Spreadsheet sheet;
	sheet.set_column_names({"First","Last","Age","Major"});
	sheet.add_row({"Person1","Last1","10000","Philosophy"});
	sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
	sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Major","chess"));
	std::stringstream out;
	sheet.print_selection(out);
	EXPECT_EQ(out.str(),"Person3 Last3 0 chess \n");
}

TEST(SelConTest, BasicFailTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Major","Chess"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}

TEST(SelConTest, BasicFailTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Major","BasketWeaving"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}

TEST(SelConTest, BasicFailTest3){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Major","chesss"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}

TEST(SelConTest, NumFindTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Age","0"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \nPerson3 Last3 0 chess \n");
}

TEST(SelConTest, NumFindTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Age","100"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \n");
}

TEST(SelConTest, NumFindFailTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"Age","100000"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"");
}

TEST(SelConTest, MultiFailTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","First","First","First"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"First","Person"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \nPerson2 Last2 -2 Basket Weaving \nPerson3 Last3 0 chess \n");
}

TEST(SelConTest, BasicThrowTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","First","First","First"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        EXPECT_THROW(sheet.set_selection(new Select_Contains(&sheet,"Last","Person")),runtime_error);
}

TEST(SelConTest, EmptyStringTest){
        Spreadsheet sheet;
        sheet.set_column_names({"First","First","First","First"});
        sheet.add_row({"","Last1","10000","Philosophy"});
        sheet.add_row({"","Last2","-2","Basket Weaving"});
        sheet.add_row({"","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"First",""));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str()," Last1 10000 Philosophy \n Last2 -2 Basket Weaving \n Last3 0 chess \n");
}

TEST(SelConTest, MultiTest3){
        Spreadsheet sheet;
        sheet.set_column_names({"First","First","First","First"});
        sheet.add_row({"Person1","Person","10000","Philosophy"});
        sheet.add_row({"person2","person","-2","Basket Weaving"});
        sheet.add_row({"Person3","Person","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"First","Person"));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Person 10000 Philosophy \nPerson3 Person 0 chess \n");
}

TEST(SelConTest, EmptyStringTest2){
        Spreadsheet sheet;
        sheet.set_column_names({"First","Last","Age","Major"});
        sheet.add_row({"Person1","Last1","10000","Philosophy"});
        sheet.add_row({"Person2","Last2","-2","Basket Weaving"});
        sheet.add_row({"Person3","Last3","0","chess"});
        sheet.set_selection(new Select_Contains(&sheet,"First",""));
        std::stringstream out;
        sheet.print_selection(out);
        EXPECT_EQ(out.str(),"Person1 Last1 10000 Philosophy \nPerson2 Last2 -2 Basket Weaving \nPerson3 Last3 0 chess \n");
}


#endif //__SEL_CON_TEST_HPP
