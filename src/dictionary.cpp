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
	Dictionary<KeyType, ValueType>::Dictionary(unsigned int table_size, unsigned int (*hash)(KeyType, unsigned int) ): table(table_size)
	{
		this->pHash = hash;
		this->num_elem = table_size;
	}

	// ctor
	template <class KeyType, class ValueType> 
	Dictionary<KeyType, ValueType>::Dictionary(): table(0)
	{
		this->pHash = NULL;
		this->num_elem = 0;
	}

	// dtor
	// free the nodes in the list
	template <class KeyType, class ValueType> 
	Dictionary<KeyType, ValueType>::~Dictionary()
	{
	}

	// inserts a key value pair into the hash table
	template <class KeyType, class ValueType> 
	void Dictionary<KeyType, ValueType>::insert(KeyType key, ValueType value)
	{
		// hash an index
		unsigned int idx = this->pHash(key, this->num_elem);

		// create the pair and push it on to the back of the list
		pair<KeyType, ValueType> p = std::make_pair(key, value);
		this->table[idx].push_back(p);
	}


	// delete entry with key 'key'
	// - size of array is decremented
	template <class KeyType, class ValueType> 
	void Dictionary<KeyType, ValueType>::erase(KeyType key)
	{
		// get the index
		unsigned int idx = this->pHash(key, this->num_elem);
		
		// search for the value in the list and delete if it exists
		for(int i=0; i<this->table[idx].size(); i++)
		{
			if(table[idx].at(i).first == key)
			{
				cout << "found erasing " << i << endl;
				this->table[idx].erase(i);
				return;
			}
		}
	}
	

	// searches for a node with 'key' and returns value of first occurence
	// - NULL if nothing is found
	template <class KeyType, class ValueType> 
	ValueType Dictionary<KeyType, ValueType>::search(KeyType key)
	{
		// get the index
		unsigned int idx = this->pHash(key, this->num_elem);
		
		// see if the value lies in the list at that index
		for(int i=0; i<this->table[idx].size() ; i++)
		{
			if(this->table[idx].at(i).first == key)
			{
				return this->table[idx].at(i).second;
			}
		}

		return NULL;
	}

	// returns the size of the hash table
	template <class KeyType, class ValueType> 
	unsigned int Dictionary<KeyType, ValueType>::size()
	{
		return this->num_elem;
	}

	


	// manually specify what datatypes are table
	// custom array containers
	template class Dictionary<string, int>;
	template class Dictionary<string, float>;
	template class Dictionary<string, double>;
	template class Dictionary<string, string>;

}
