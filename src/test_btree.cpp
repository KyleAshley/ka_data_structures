/******************************************************************/
// test_btree.cpp
// Author: Kyle Ashley
// 
// Test code for implementations of BST
/******************************************************************/

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h>

#include "btree.h"

using namespace std;


// test the functionality of various datastructures
int main( int argc, char** argv) {

	cout << "Testing BST.." << endl;
	kads::bTree<int> tree;
	
	tree.insert(1, tree.getHead());

	cout << tree.search(1, tree.getHead()) << " " << tree.search(2, tree.getHead()) << endl;

	tree.insert(10, tree.getHead());
	tree.insert(15, tree.getHead());
	tree.insert(2, tree.getHead());
	tree.insert(-6, tree.getHead());

	cout << tree.search(1, tree.getHead()) << " " << tree.search(2, tree.getHead()) << endl;



	return 0;

}