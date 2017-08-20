/******************************************************************/
// heap.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic min/max heap
/******************************************************************/

#include "heap.h"

namespace kads
{

	template <class ValueType> 
	Heap<ValueType>::Heap()
	{
		this->head = NULL;
	}

	template <class ValueType> 
	Heap<ValueType>::~Heap()
	{

	}


	// some basic bTree types
	template class Heap<int>;
	template class Heap<float>;
	template class Heap<double>;
	template class Heap<string>;
	
}