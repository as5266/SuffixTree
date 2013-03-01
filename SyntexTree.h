//
//  SyntexTree.h
//
//  Created by Abhishek Suri on 12/14/12.
//  Copyright (c) 2012 Abhishek Suri. All rights reserved.
//

#ifndef __SyntexTree__
#define __SyntexTree__

#include <iostream>
#include <string>
#include <sstream>
#include "utils.h"

using namespace std;

// Data Structure used for storing the character read from input file
struct node {
	string word;
	node *left;
	node *right;
};

//Main structure used for creating the Syntex tree
class SynTree {
    node *root;
public:
	SynTree();
	void addNode(string data);
	// joining two trees
	void joinTrees (SynTree* T1);
	// interface to user for printing tree
	void show() ;
	// Function peforming the calculatons
	string calc(string op, string var1, string var2);
	//function used for calling the calc
	string reduce (node* T) ;
    string evalTree();
	// Printer; Can be modified to view the postfix or infix notation
    static void prefixer (node *T) {
        if(T != NULL) {
            cout<<" "<<T->word;
            prefixer(T->left);
            prefixer(T->right);
        }
    }
    
};

// Function for comparing the priority of operators
int priority (string s);

#endif /* defined(__Twitch__SyntexTree__) */
