#ifndef __SELECT_HPP__
#define __SELECT_HPP__

#include <cstring>
#include <string>
#include <iostream>

#include "spreadsheet.hpp"

using namespace std;

class Select
{

public:
    virtual ~Select() = default;

    virtual bool select(const Spreadsheet* sheet, int row) const = 0;
};

class Select_Column: public Select
{
protected:
    int column;
public:
    Select_Column(const Spreadsheet* sheet, const std::string& name)
    {
	       column = sheet->get_column_by_name(name);
    }
    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return select(sheet->cell_data(row, column));
    }

	virtual bool select(const std::string& s) const = 0;
};


class Select_Contains: public Select_Column
{
private:
    string str_;
public:
    Select_Contains(const Spreadsheet* sheet, const string& name, const string& str):Select_Column(sheet, name){
        str_ = str;
	if(column == -1) {
      		throw(invalid_argument("Invalid column name"));
	}
   }
    }
    virtual bool select(const string& s) const{
    	if(s.find(str_) != string::npos){
    		return true;
    	}
    	return false;
    }

};

class Select_Not: public Select
{
private:
    Select* select1_;
public:
    Select_Not(Select* select1){
        select1_ = select1;
    }
    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        return !(select1_->select(sheet, row));
    }

    ~Select_Not() {
	delete select1_;
	select1_ = nullptr;

	}

};

class Select_And: public Select
{
private:
    Select* select1_;
    Select* select2_;
public:
    Select_And(Select* select1, Select* select2){
        select1_ = select1;
        select2_ = select2;
    }
    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        bool x = select1_->select(sheet, row);
        bool y = select2_->select(sheet, row);
        return x&&y;
    }

   ~Select_And() {
	delete select1_;
	delete select2_;

	select1_ = nullptr;
	select2_ = nullptr;

   }

};

class Select_Or: public Select
{
private:
    Select* select1_;
    Select* select2_;
public:
    Select_Or(Select* select1, Select* select2){
        select1_ = select1;
        select2_ = select2;
    }
    virtual bool select(const Spreadsheet* sheet, int row) const
    {
        bool x = select1_->select(sheet, row);
        bool y = select2_->select(sheet, row);
        return x||y;
    }

    ~Select_Or() {
	delete select1_;
	delete select2_;

	select1_ = nullptr;
	select2_ = nullptr;

	}

};

#endif //__SELECT_HPP___

