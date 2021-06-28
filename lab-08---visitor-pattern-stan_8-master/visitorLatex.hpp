#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include <iostream>
#include <string>

#include "visitor.hpp"
#include "src/base.hpp"
#include "src/add.hpp"
#include "src/op.hpp"
#include "src/mult.hpp"
#include "src/sub.hpp"
#include "src/div.hpp"
#include "src/pow.hpp"
#include "src/rand.hpp"
#include "iterator.hpp"

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class VisitorLatex : public Visitor{
private:
    string latex = "";
public:
    VisitorLatex(){}

    string PrintLaTeX(Base* ptr){
      VisitorLatex* visitor_ = new VisitorLatex();
    	for (Iterator it(ptr); !it.is_done(); it.next()){
        	it.current_node()->accept(visitor_, it.current_index());
    	}

   	string latexFormat = visitor_->getLatex();

   	delete visitor_;

   	return latexFormat;

      }

    virtual ~VisitorLatex() = default;

    string getLatex(){
        latex = "$" + latex;
        latex = latex + "$";
        return latex;
    }

    virtual void visit_op(Op* node){
        latex = latex + "{";
        latex = latex + node->stringify();
        latex = latex + "}";
    }
    virtual void visit_rand(Rand* node){
	latex = latex + "{";
        latex = latex + node->stringify();
        latex = latex + "}";
    }
        virtual void visit_add_begin(Add* node){
        latex = latex + "{(";
    }
    virtual void visit_add_middle(Add* node){
        latex = latex + "+";
    }
    virtual void visit_add_end(Add* node){
        latex = latex + ")}";
    }
    virtual void visit_sub_begin(Sub* node){
        latex = latex + "{(";
    }
    virtual void visit_sub_middle(Sub* node){
        latex = latex + "-";
    }
    virtual void visit_sub_end(Sub* node){
        latex = latex + ")}";
    }
    virtual void visit_mult_begin(Mult* node){
        latex = latex + "{(";
    }
    virtual void visit_mult_middle(Mult* node){
        latex = latex + "\\cdot";
    }
    virtual void visit_mult_end(Mult* node){
        latex = latex + ")}";
    }
    virtual void visit_div_begin(Div* node){
        latex = latex + "{\\frac"; 
    }
    virtual void visit_div_middle(Div* node){
		
    }
    virtual void visit_div_end(Div* node){
        latex = latex + "}";
    }
    virtual void visit_pow_begin(Pow* node){
        latex = latex + "{(";
    }
    virtual void visit_pow_middle(Pow* node){
        latex = latex + "^";
    }
    virtual void visit_pow_end(Pow* node){
        latex = latex + ")}";
    }

};

#endif //__VISITORLATEX_HPP__

