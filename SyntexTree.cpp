//
//  SyntexTree.cpp
//
//  Created by Abhishek Suri on 12/14/12.
//  Copyright (c) 2012 Abhishek Suri. All rights reserved.
//

#include "SyntexTree.h"

enum Op {
    START_BRACE = 0,
    DIV,
    MUL,
    ADD,
    SUB,
    END_BRACE,
    SYMBOL
};

static int getOperation(string op){
    if("(" == op)
        return START_BRACE;
	else if("/" == op)
		return DIV;
	else if("*" == op)
		return MUL;
	else if("+" == op)
		return ADD;
	else if("-" == op)
		return SUB;
    else if(")" == op)
        return END_BRACE;
	else
		return SYMBOL; // unknown reference
}

// Function for comparing the priority of operators
int priority (string s)
{
	if (s == "/" || s == "*" )
		return 2;
	else if (s == "+" || s == "-")
		return 1;
}


SynTree::SynTree() {
		root = NULL;
}
void SynTree::addNode(string data) {
    node *temp;
    temp = new node;
    temp->word = data;
    temp->left = NULL;
    temp->right = NULL;
    
    int test = 0;
    test = getOperation(data);
    // Case: Data is numeric
    if (test == SYMBOL) {
        // Case: Data is numeric and no previous data read
        if (root == NULL ) {
            root = temp;
        }
        //Case : Data is numeric and there exists some previous data
        else if (root != NULL ) {
            node *position;
            position = root;
            if(position->left == NULL ) {
					position->left = temp;
            }
            else {
                while (position->right != NULL) {
                    position = position->right;
                }
                if(position->left == NULL ){
                    position->left = temp;
                }
                else {
                    position->right = temp;
                }
            }
        }
    }
    //Case : Data is a symbol
    else {
        int test2 = getOperation(root->word);
        //data is symbol and root is numeric
        if( test2 == SYMBOL) {
            temp->left = root;
            root = temp;
        }
        //sub case: Data and root symbols are of equal precedence
        else if ( priority(data) == priority(root->word) ) {
            temp->left = root;
            root = temp;
        }
        // Data and root symbol are of different precedence
        else if ( priority(data) > priority(root->word)  ) {
            node *leaf;
            leaf = new node;
            leaf = root->right;
            root->right = temp;
            temp->left = leaf;
        }
        // testing to find the new root for the syntex tree
        else if ( priority(data) < priority(root->word)  ) {
				temp->left = root;
				root = temp;
        }
    }
}
    
	// joining two trees
void SynTree::joinTrees(SynTree* T1) {
    node *position;
    position = root;
    
    node* prev;
    while (position != NULL) {
        prev = position;
        position = position->right;
    }
    position = prev;
    
    if (position->left == NULL) {
        position->left = T1->root ;
    }
    else {
        position->right = T1->root;
    }
}

// interface to user for printing tree
void SynTree::show() {
    node *position = root;
    prefixer(position);
    cout<<endl;
}

// Function peforming the calculatons
string SynTree::calc(string op, string var1, string var2) {
    int temp1,temp2;
    temp1 = toInt(var1);
    temp2 = toInt(var2);
    string ans;
    stringstream holder;
    
    if ( isNumber(var1) && isNumber(var2) ) {
        if (op == "+") {
            temp1 += temp2;
        }
        else if (op == "-") {
            temp1 = temp1 - temp2;
        }
        else if (op == "*") {
            temp1 = temp1*temp2;
        }
        else {
            temp1 = temp1 / temp2 ;
        }
        holder <<temp1;
        ans = holder.str();
        return ans;
    }
    else {
        return ("( "+op+" "+var1+" "+var2+" )");
    }
}

//function used for calling the calc
string SynTree::reduce (node* T) {
    if (T->left == NULL && T->right == NULL) {
        return T->word;
    }
    else {
        return calc(T->word,reduce(T->left),reduce(T->right));
    }
}

string SynTree::evalTree() {
    return reduce(root);
}