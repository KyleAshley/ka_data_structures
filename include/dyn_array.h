#ifndef DYN_ARRAY_H_
#define DYN_ARRAY_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 


using namespace std;

namespace kads
{
	template <class T> class DynArray {
		
		public:

			// default ctor and dtor
			DynArray();
			~DynArray();

			// create a list with 'size' nodes all initialized with 'value'
			DynArray(int size, T value);

			// inserts a new node with 'value' at the end of the array, 
			// - size of array is incremented
			void push_back(T value);	

			void insert(T value, int idx);

			// delete value at index 'idx', 
			// - size of array is decremented
			void erase(int idx);

			// returns the size of the array
			int size();
			

		private:
			T* pArray;
			int num_elem;

	};


}


		
#endif



















