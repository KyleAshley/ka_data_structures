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
															  unsigned int (*hash)(KeyType, unsigned int) )
	{
		this->pHash = hash;
		this->size = table_size;
		this->pTable = new DynArray<LinkedList<pair<KeyType, ValueType> > >(table_size, LinkedList<std::pair<KeyType, ValueType> >());

	}

	// ctor
	template <class KeyType, class ValueType> 
	Dictionary<KeyType, ValueType>::Dictionary()
	{
		this->pHash = NULL;
		this->size = 0;
		this->pTable = NULL;
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

		// add to linked list at that index
		if(pTable[idx].size() == 0)
		{
			cout << "empty" << endl;
		}
		else
		{

		}
		
	}

	/*

	// delete entry with key 'key'
	// - size of array is decremented
	template <class KeyType, class ValueType, class ContainerType> 
	void Dictionary<KeyType, ValueType>::erase(KeyType key)
	{

	}

	// inserts a new node with 'value' at the end of the array, 
	// - size of array is incremented
	template <class KeyType, class ValueType, class ContainerType> 
	ValueType Dictionary<KeyType, ValueType>::search(KeyType key)
	{

	}

	*/


	// manually specify what datatypes are acceptable
	// custom array containers
	template class Dictionary<string, int>;
	template class Dictionary<string, float>;
	template class Dictionary<string, double>;
	template class Dictionary<string, string>;

}
