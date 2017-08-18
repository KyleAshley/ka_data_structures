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
	template <class KeyType, class ValueType>  class Dictionary {
		
		public:

			// default ctor and dtor
			Dictionary();
			Dictionary(unsigned int table_size, unsigned int (*hash)(KeyType, unsigned int) );
			~Dictionary();

			// inserts a key value pair in the dictionary
			void insert(KeyType key, ValueType value);

			// delete entry with key 'key'
			// - size of array is decremented
			void erase(KeyType key);

			// searches for an entry with the specified key and returns it
			ValueType search(KeyType key);	

			// returns the size of the hash table
			unsigned int size();
			

		private:
			// size of the hash table
			unsigned int num_elem;

			// pointer to hash function (set by constructor)
			unsigned int (*pHash)(KeyType, unsigned int);

			DynArray<LinkedList<std::pair<KeyType, ValueType> > > table;


	};


}


		
#endif