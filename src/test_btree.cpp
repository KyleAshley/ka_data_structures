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
	
	tree.insert(10, tree.getHead());

	cout << tree.search(1, tree.getHead()) << " " << tree.search(2, tree.getHead()) << endl;

	tree.insert(5, tree.getHead());
	tree.insert(15, tree.getHead());
	tree.insert(1, tree.getHead());
	tree.insert(8, tree.getHead());
	tree.insert(12, tree.getHead());
	tree.insert(17, tree.getHead());


	cout << tree.search(1, tree.getHead()) << " " << tree.search(2, tree.getHead()) << endl;

	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());
	cout << "preorder" << endl;
	tree.preOrderPrint(tree.getHead());
	cout << "postorder" << endl;
	tree.postOrderPrint(tree.getHead());

	cout << tree.getMin(tree.getHead())->value << " " << tree.getMax(tree.getHead())->value << endl;

	tree.erase(5, tree.getHead());
	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());

	tree.erase(17, tree.getHead());
	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());

	tree.erase(17, tree.getHead());
	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());

	tree.erase(10, tree.getHead());
	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());

	tree.erase(12, tree.getHead());
	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());

	cout << "insertin" << endl;
	tree.insert(5, tree.getHead());
	tree.insert(15, tree.getHead());
	tree.insert(1, tree.getHead());
	tree.insert(8, tree.getHead());
	tree.insert(11, tree.getHead());
	tree.insert(12, tree.getHead());
	tree.insert(17, tree.getHead());

	tree.erase(12, tree.getHead());
	cout << "inorder" << endl;
	tree.inOrderPrint(tree.getHead());


	return 0;

}