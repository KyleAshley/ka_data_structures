/******************************************************************/
// test_dictionary.cpp
// Author: Kyle Ashley
// 
// Test code for implementation of dictionary
/******************************************************************/

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h>

#include "dictionary.h"

using namespace std;

unsigned int hashfunc(string key, unsigned int table_size);

unsigned int hashfunc(string key, unsigned int table_size)
{
	cout << key << endl;
	unsigned int i=0;
	int seed = 37;
	unsigned int hash = 0;
	while(i < key.size())
	{
		hash = (hash * seed) + key[i];
		i++;
	}
	return  hash % table_size;
}

// test the functionality of various datastructures
int main( int argc, char** argv) {

	cout << "Testing Dictionary.." << endl;

	// create a dictionary
	unsigned int size = 100;
	kads::Dictionary<string, int, vector<int> > dict( size, hashfunc );

	return 0;

}