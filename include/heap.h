// Implemetation of a Min/Max Heap
// Properties:  
// - Fullfills the heap property after each operation where:
//		- Each child is < or > its parent
// - The heap will be represented as a complete binary tree after each operation
//		- Height is always lg(n)
// - Will store either the min/max element at the root node resulting in O(1) access
// -

#ifndef HEAP_H_
#define HEAP_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 

#include "dyn_array.h"

using namespace std;



namespace kads
{
	// basic min/max heap datastructure
	template <class ValueType> class heap {
		
		public:



		private:
			bNode<ValueType>* head;

	};

}

#endif