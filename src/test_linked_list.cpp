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
	cout << "List is size: " << l.size() << endl;

	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << "Inserting at begining" << endl;
	l.insert(4, 0);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << "Inserting at end" << endl;
	l.insert(5, l.size()+1);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << "Inserting at 2" << endl;
	l.insert(6, 2);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << "Deleting 2" << endl;
	l.erase(2);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << "Deleting 0" << endl;
	l.erase(0);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << "Deleting end" << endl;
	l.erase(l.size()-1);
	l.print();
	cout << "List is size: " << l.size() << endl;

	cout << l.at(0) << endl;
	cout << l.at(1) << endl;
	cout << l.at(l.size()-1) << endl;
	cout << l.at(l.size()-3) << endl;


	return 0;

}