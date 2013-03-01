//
//  Prefixer.cpp
//
//  Created by Abhishek Suri on 12/14/12.
//  Copyright (c) 2012 Abhishek Suri. All rights reserved.
//

#include "Prefixer.h"
#include "string.h"
#include "utils.h"
#include <sstream>

// Defining Solver
SynTree* solver(SynTree* T, string &line) {

    while( line.length() ) {
        int pos = (int) line.find(" ");
        string token;
        // tokenize and modify the original string
        if(pos != string::npos) {
            token = line.substr(0,pos);
            line = line.substr(pos+1,line.length());
        }
        else {
            token = line;
            line = "";
        }
        
        // take actions based on token type
		if (token != "(" && token != ")" ) {
			T->addNode(token);
		}
		else if (token == "(" ) {
			SynTree *temp = new SynTree;
			T->joinTrees(solver( temp, line)); //
		}
		else if (token == ")") {
			return T;
		}
	}
	return T;

}