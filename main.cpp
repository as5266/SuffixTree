//
//  main.cpp
//
//  Created by Abhishek Suri on 12/14/12.
//  Copyright (c) 2012 Abhishek Suri. All rights reserved.
//

#include <iostream>
#include "Prefixer.h"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
//#define _TEST_
#ifdef _TEST_
    string str = "2 * ( 5 + 1 )";
    SynTree* myTree = new SynTree;
    myTree = solver (myTree,str);
    
    if(argc == 2)
        myTree->show();

#else
    if (argc < 2) {
		cout<<"Usage: prefixer <input file> [-r]"<<endl;
	}
	else if (argc >= 2 ) {
		
		ifstream fin(argv[1]);
        string line;
        while(getline(fin,line)) {
            SynTree* myTree = new SynTree;
            myTree = solver (myTree,line);

            if(argc == 2)
                myTree->show(); 
            else if (argc == 3 && !strcmp(argv[2],"-r") ) 
                cout << myTree->evalTree()<<endl;
            else 
                cout<<"Usage: prefixer <input file> [-r]"<<endl;
            
            free(myTree);
        }
	}
#endif
    return 0;
}

