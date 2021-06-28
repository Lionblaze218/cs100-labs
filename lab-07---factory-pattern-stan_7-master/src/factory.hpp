#ifndef FACTORY_HPP
#define FACTORY_HPP

using namespace std;

//misc.
#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <string.h>
#include <stdio.h>

//header files
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"

class factory {
	private:
		Base* root;
		Base* left;
	public:
		factory() { root = nullptr; left = nullptr; }
		~factory() {}

		Base* parse(char** input, int length) {
			root = nullptr;
			int i = 0;
			if(!isdigit(*(input[0]))) {
				cout << "ERROR" << endl;
				return nullptr;
			}
			while(i <  length){
				if(strcmp(input[i],"+") == 0) {
					if(!isdigit(*(input[i+1]))) {
                                		cout << "ERROR" << endl;
                                		return nullptr;
                        		}
					left = root;
					root = new Add(left, new Op(stod(input[++i])));
				}
				else if(strcmp(input[i],"-") == 0) {

					if(!isdigit(*(input[i+1]))) {
                                                cout << "ERROR" << endl;
                                                return nullptr;
                                        }

					left = root;
					root = new Sub(left, new Op(stod(input[++i])));
				}

				else if(strcmp(input[i],"*") == 0) {
					if(!isdigit(*(input[i+1]))) {
                                                cout << "ERROR" << endl;
                                                return nullptr;
                                        }

					left = root;
					root = new Mult(left, new Op(stod(input[++i])));
				}
				else if(strcmp(input[i],"/") == 0) {
					if(!isdigit(*(input[i+1]))) {
                                                cout << "ERROR" << endl;
                                                return nullptr;
                                        }

					left = root;
					root = new Div(left, new Op(stod(input[++i])));
				}
				else if(strcmp(input[i],"**") == 0) {
					if(!isdigit(*(input[i+1]))) {
                                                cout << "ERROR" << endl;
                                                return nullptr;
                                        }
					left = root;
					root = new Pow(left, new Op(stod(input[++i])));
				}

				else if(isdigit(*(input[i]))) {
					left = new Op(stod(input[i]));
					root = left;
				}
				else {
					cout << "ERROR" << endl;
					return nullptr;

				}
				i++;

			}
			return root;
		}
};
#endif //FACTORY_HPP

