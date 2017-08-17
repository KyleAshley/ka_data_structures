/******************************************************************/
// dictionary.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic dictionary implemented as a hash table
/******************************************************************/

#include "dictionary.h"

namespace kads
{

	// ctor
	template <class KeyType, class ValueType> 
	Dictionary<KeyType, ValueType>::Dictionary(unsigned int table_size, 
															  unsigned int (*hash)(KeyType, unsigned int) ):
												pTable(table_size)
	{
		this->pHash = hash;
		this->size = table_size;

	}

	// ctor
	template <class KeyType, class ValueType> 
	Dictionary<KeyType, ValueType>::Dictionary(): pTable(0)
	{
		this->pHash = NULL;
		this->size = 0;
	}

	// dtor
	// free the nodes in the list
	template <class KeyType, class ValueType> 
	Dictionary<KeyType, ValueType>::~Dictionary()
	{
	}

	template <class KeyType, class ValueType> 
	void Dictionary<KeyType, ValueType>::insert(KeyType key, ValueType value)
	{
		// hash an index
		unsigned int idx = this->pHash(key, this->size);

		pair<KeyType, ValueType> p = std::make_pair(key, value);
		cout << "inserting" << endl;
		pTable[idx].push_back(p);
		
	}


	// delete entry with key 'key'
	// - size of array is decremented
	template <class KeyType, class ValueType> 
	void Dictionary<KeyType, ValueType>::erase(KeyType key)
	{
		// get the index
		unsigned int idx = this->pHash(key, this->size);
		
		// search for the value in the list and delete if it exists
		for(int i=0; i<this->pTable[idx].size(); i++)
		{
			if(pTable[idx].at(i).first == key)
			{
				pTable[idx].erase(i);
			}
		}
	}
	

	// inserts a new node with 'value' at the end of the array, 
	// - size of array is incremented
	template <class KeyType, class ValueType> 
	ValueType Dictionary<KeyType, ValueType>::search(KeyType key)
	{
		// get the index
		unsigned int idx = this->pHash(key, this->size);
		
		// see if the value lies in the list at that index
		for(int i=0; i<this->pTable[idx].size(); i++)
		{
			if(pTable[idx].at(i).first == key)
			{
				return pTable[idx].at(i).second;
			}
		}

		return 0;
	}

	


	// manually specify what datatypes are acceptable
	// custom array containers
	template class Dictionary<string, int>;
	template class Dictionary<string, float>;
	template class Dictionary<string, double>;
	template class Dictionary<string, string>;

}
