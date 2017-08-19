#ifndef DYN_ARRAY_H_
#define DYN_ARRAY_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 

#include "linked_list.h"

using namespace std;

namespace kads
{
	// basic templated dynamic array class
	// - this class was implemented as an exercise to understand 
	//   dynamic memory management
	template <class T> class DynArray {
		
		public:

			// default ctor and dtor
			DynArray();
			~DynArray();

			// - create a list with 'size' nodes
			DynArray(int size);

			// - create a list with 'size' nodes all initialized with 'value'
			DynArray(int size, T value);

			// - inserts a new node with 'value' at the end of the array, 
			// - size of array is incremented
			void push_back(T value);	

			void insert(T value, int idx);

			// - delete value at index 'idx', 
			// - size of array is decremented
			void erase(int idx);

			// - returns the value at index 'idx' with boundary checking
			T at(int idx);

			// - returns the size of the array
			int size();

			// overloaded indexing operators
			inline T const& operator[](int index) const { return this->pArray[index]; } 
			inline T& operator[](int index) { return this->pArray[index]; } 

		private:
			T* pArray;
			int num_elem;

	};


}


		
#endif



















