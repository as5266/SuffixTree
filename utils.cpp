//
//  utils.cpp
//
//  Created by Abhishek Suri on 12/14/12.
//  Copyright (c) 2012 Abhishek Suri. All rights reserved.
//

#include "utils.h"
#include <sstream>

int toInt(string str){
    int num;
    stringstream(str)>> num;
    return num;
}

bool isNumber(string str) {
	bool ret = true;
	for(int index = 0; index < str.length(); ++index) {
		if(!isdigit(str[index])) {
			ret = false;
			break;
		}
	}
	return ret;
}

string toString(int num) {
    ostringstream oss;
    oss << num;
    return oss.str();
}

vector<string> myStrtok(string str,string tokenizer) {
    vector<string> ret;
    while(str.length() > 0) {
        int pos = (int) str.find_first_of(tokenizer);
        
        if(pos != string::npos) {
            ret.push_back( str.substr(0,pos) );
            str = str.substr(pos + tokenizer.length(),str.length());
        }
        else {
            ret.push_back(str);
            break;
        }
    }
    return ret;
}

string getStringFromVector(const vector<string>& vec, int index) {
    string ret;
    for (int position = index; position < vec.size(); ++position) {
        ret += vec[position];
        ret += " ";
    }
    cout<<ret<<endl;
    return ret;
}
