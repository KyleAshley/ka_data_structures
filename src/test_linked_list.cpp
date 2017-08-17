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
	int num_nodes = 0;
	cout << "Creating Linked List of size: " << num_nodes << endl;
	//kads::LinkedList<std::pair<string, int> > l(num_nodes, std::make_pair("hello", 10));
	kads::LinkedList<std::pair<string, int> > l;
	for(int i=0; i<l.size(); i++)
	{
		cout << l.at(i).first << endl;
	}

	l.push_back(make_pair("hello2", 20));
	cout << "Size: " << l.size() << endl;

	for(int i=0; i<l.size(); i++)
	{
		cout << l.at(i).first << endl;
	}
	l.erase(0);

	/*
	kads::LinkedList<int> l(num_nodes, 0);
	
	cout << "List is size: " << l.size() << endl;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	cout << "List is size: " << l.size() << endl;

	cout << "Inserting at begining" << endl;
	l.insert(4, 0);
	
	cout << "List is size: " << l.size() << endl;

	cout << "Inserting at end" << endl;
	l.insert(5, l.size());
	
	cout << "List is size: " << l.size() << endl;

	cout << "Inserting at 2" << endl;
	l.insert(6, 2);
	
	cout << "List is size: " << l.size() << endl;

	cout << "Deleting 2" << endl;
	l.erase(2);
	
	cout << "List is size: " << l.size() << endl;

	cout << "Deleting 0" << endl;
	l.erase(0);
	
	cout << "List is size: " << l.size() << endl;

	cout << "Deleting end" << endl;
	l.erase(l.size()-1);
	
	cout << "List is size: " << l.size() << endl;

	cout << l.at(0) << endl;
	cout << l.at(1) << endl;
	cout << l.at(l.size()-1) << endl;
	cout << l.at(l.size()-3) << endl;

	cout << "Pop back" << endl;
	l.pop_back();
	
	cout << "Pop back" << endl;
	l.pop_back();
	
	cout << "Push back" << endl;
	l.push_back(5);
	
	cout << "Push back" << endl;
	l.push_back(8);
	
	cout << "Pop front" << endl;
	l.pop_front();

	cout << "Push front" << endl;
	l.push_front(11);
	
	cout << "Push front" << endl;
	l.push_front(12);
	*/
	

	return 0;

}