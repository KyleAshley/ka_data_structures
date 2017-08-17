#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 

#include <dyn_array.h>
#include <linked_list.h>
#include <vector>

using namespace std;

namespace kads
{
	template <class KeyType, class ValueType, class ContainerType>  class Dictionary {
		
		public:

			// default ctor and dtor
			Dictionary();
			Dictionary(unsigned int table_size, unsigned int (*hash)(string, unsigned int) );
			~Dictionary();

			// inserts a new node with 'value' at the end of the array, 
			// - size of array is incremented
			ValueType search(KeyType key);	

			void insert(KeyType key, ValueType value);

			// delete entry with key 'key'
			// - size of array is decremented
			void erase(KeyType key);

			

		private:
			// size of the hash table
			unsigned int size;

			// pointer to hash function (set by constructor)
			unsigned int (*pHash)(string, unsigned int);


	};


}


		
#endif