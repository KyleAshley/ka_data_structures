#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 


#include <linked_list.h>
#include <dyn_array.h>


using namespace std;

namespace kads
{

	// basic templated dictionary class implemented as a hash table
	// - this class was implemented as an exercise to understand 
	//   hash tables
	// - underlying containers are custom DynArray and LinkedList 
	//   which function similar to STL vector and list respectively 
	// - utilizes chaining for collision mitigation
	template <class KeyType, class ValueType>  class Dictionary {
		
		public:

			// default ctor and dtor
			Dictionary();
			Dictionary(unsigned int table_size, unsigned int (*hash)(KeyType, unsigned int) );
			~Dictionary();

			// inserts a key value pair in the dictionary
			// - chaining is used for collision mitigation where entries are added to the end of the list
			void insert(KeyType key, ValueType value);

			// delete entry with key 'key'
			// - size of array is decremented
			void erase(KeyType key);

			// returns index of element with matching key, NULL if not found
			ValueType search(KeyType key);	

			// returns the size of the hash table
			unsigned int size();
			

		private:
			// size of the hash table
			unsigned int num_elem;

			// pointer to hash function (set by constructor)
			unsigned int (*pHash)(KeyType, unsigned int);

			// pointer to the hash table table
			// - each element contains a linked list of key/value pairs
			DynArray<LinkedList<std::pair<KeyType, ValueType> > > table;


	};


}


		
#endif