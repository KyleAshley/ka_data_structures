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

#include "dyn_array.h"

using namespace std;


// test the functionality of various datastructures
int main( int argc, char** argv) {

	cout << "Testing Dynamic Array.." << endl;
	int num_nodes = 10;
	cout << "Creating Dynamic Array of size: " << num_nodes << endl;
	kads::DynArray<int> arr(num_nodes, 0);
	cout << arr.size() << endl;
	


	return 0;

}