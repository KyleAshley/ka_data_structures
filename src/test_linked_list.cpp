/******************************************************************/
// test_linked_list.cpp
// Author: Kyle Ashley
// 
// Test code for implementations of linked list
/******************************************************************/

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h>

#include "linked_list.h"

using namespace std;


// test the functionality of various datastructures
int main( int argc, char** argv) {

	cout << "Testing Linked List.." << endl;
	int num_nodes = 10;
	cout << "Creating Linked List of size: " << num_nodes << endl;
	kads::LinkedList<int> l(num_nodes, 0);
	l.print();

	return 0;

}