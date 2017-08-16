/******************************************************************/
// dictionary.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic doubly linked list
/******************************************************************/

#include "dictionary.h"

namespace kads
{

	// ctor
	template <class KeyType, class ValueType, class ContainerType> 
	Dictionary<KeyType, ValueType, ContainerType>::Dictionary(unsigned int table_size, 
															  unsigned int (*hash)(string, 
															  unsigned int) )
	{
		this->*pHash = *hash;
	}

	// dtor
	// free the nodes in the list
	template <class KeyType, class ValueType, class ContainerType> 
	Dictionary<KeyType, ValueType, ContainerType>::~Dictionary()
	{
	
	}

	/*
	// inserts a new node with 'value' at the end of the array, 
	// - size of array is incremented
	template <class KeyType, class ValueType, class ContainerType> 
	ValueType Dictionary<KeyType, ValueType, ContainerType>::search(KeyType key)
	{

	}

	template <class KeyType, class ValueType, class ContainerType> 
	void Dictionary<KeyType, ValueType, ContainerType>::insert(KeyType key, ValueType value)
	{

	}

	// delete entry with key 'key'
	// - size of array is decremented
	template <class KeyType, class ValueType, class ContainerType> 
	void Dictionary<KeyType, ValueType, ContainerType>::erase(KeyType key)
	{

	}
	*/


	// manually specify what datatypes are acceptable
	template class Dictionary<int, int, DynArray<int> >;
	template class Dictionary<int, float, DynArray<float> >;
	template class Dictionary<int, double, DynArray<double> >;
	template class Dictionary<int, string, DynArray<string> >;

	template class Dictionary<float, int, DynArray<int> >;
	template class Dictionary<float, float, DynArray<float> >;
	template class Dictionary<float, double, DynArray<double> >;
	template class Dictionary<float, string, DynArray<string> >;

	template class Dictionary<double, int, DynArray<int> >;
	template class Dictionary<double, float, DynArray<float> >;
	template class Dictionary<double, double, DynArray<double> >;
	template class Dictionary<double, string, DynArray<string> >;

	template class Dictionary<string, int, DynArray<int> >;
	template class Dictionary<string, float, DynArray<float> >;
	template class Dictionary<string, double, DynArray<double> >;
	template class Dictionary<string, string, DynArray<string> >;

}
