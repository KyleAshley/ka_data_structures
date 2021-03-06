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
#include "linked_list.h"

using namespace std;


// test the functionality of various datastructures
int main( int argc, char** argv) {

	cout << "Testing Dynamic Array.." << endl;
	int num_nodes = 1;
	cout << "Creating Dynamic Array of size: " << num_nodes << endl;
	
	kads::DynArray<kads::LinkedList<pair<string, int> > > arr(num_nodes);
	arr[0].push_back(make_pair("hi", 1));
	arr[0].erase(0);
	

	/*
	kads::DynArray<int> arr(num_nodes, 0);
	cout << "Size: " << arr.size() << endl;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	cout << "Size: " << arr.size() << endl;

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;
	

	arr.insert(5, 0);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.insert(6, arr.size());

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.insert(7, 3);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(0);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(arr.size()-1);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(5);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(4);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(3);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(2);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(1);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;

	arr.erase(0);

	for(int i=0; i<arr.size(); i++)
		cout << arr[i] << endl;
	cout << "---------------------" << endl;
	*/


	return 0;

}