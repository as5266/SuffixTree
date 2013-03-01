//
//  utils.h
//
//  Created by Abhishek Suri on 12/14/12.
//  Copyright (c) 2012 Abhishek Suri. All rights reserved.
//

#ifndef __utils__
#define __utils__

#include <iostream>
#include <string>
#include <vector>

using namespace std;



bool isNumber(string str);
string toString(int num);
int toInt(string str);
vector<string> myStrtok(string line,string tokenizer);
string getStringFromVector(const vector<string>& vec, int index);
#endif /* defined(__utils__) */
