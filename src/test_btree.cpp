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

	tree.insert(2, tree.getHead());
	tree.insert(3, tree.getHead());
	tree.insert(4, tree.getHead());
	tree.insert(5, tree.getHead());


	cout << tree.search(1, tree.getHead()) << " " << tree.search(2, tree.getHead()) << endl;

	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());
	cout << "preorder" << endl;
	tree.preOrderPrint(tree.getHead());
	cout << "postorder" << endl;
	tree.postOrderPrint(tree.getHead());

	cout << tree.getMin()->value << " " << tree.getMax()->value << endl;



	return 0;

}