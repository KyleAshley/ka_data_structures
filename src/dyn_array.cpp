/******************************************************************/
// dyn_array.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic dynamic array class
/******************************************************************/

#include "dyn_array.h"

namespace kads
{

	// ctor
	template <class T> 
	DynArray<T>::DynArray()
	{
		this->pArray = NULL;
		this->num_elem = 0;
	}

	// dtor
	template <class T> 
	DynArray<T>::~DynArray()
	{
		delete [] pArray;
	}

	// creates a new carray with 'num_nodes' elements
	// Complexity: O(n)
	template <class T> 
	DynArray<T>::DynArray(int num_nodes)
	{	
		// create the array
		if(num_nodes > 0)
		{
			this->pArray = new T[num_nodes];

			// set the size of the array
			this->num_elem = num_nodes;
		}
	}

	// creates a new carray with 'num_nodes' elements initialized to 'val'
	// Complexity: O(n)
	template <class T> 
	DynArray<T>::DynArray(int num_nodes, T val)
	{	
		// create the array
		if(num_nodes > 0)
		{
			this->pArray = new T[num_nodes];

			// assign an initial value to each element
			for(int i=0; i<num_nodes; i++)
			{
				this->pArray[i] = val;
			}

			// set the size of the array
			this->num_elem = num_nodes;
		}
	}

	// adds an element at the end of the array increasing size by 1
	// Complexity: O(n)
	// TODO: make this amortized O(n) by allocating extra space a-la-vector
	template <class T> 
	void DynArray<T>::push_back(T val)
	{
		// create a new array of size=1
		int new_size = this->num_elem+1;
		T* new_arr = new T[new_size];

		// copy old values over
		for(int i=0; i<this->num_elem; i++)
		{
			new_arr[i] = this->pArray[i];
		}
		new_arr[new_size-1] = val;
		
		// copy it over
		T* tmp = pArray;
		this->pArray = new_arr;
		delete [] tmp;

		// set the new size
		this->num_elem = new_size;

	}

	// inserts an element at the specified index increasing size by 1
	// Complexity: O(n)
	template <class T> 
	void DynArray<T>::insert(T val, int idx)
	{
		if(idx < 0 || idx > this->num_elem)
		{
			cerr << "Invalid index for insert at index: " << idx << endl;
			return;
		}

		// create a new array of size=1
		int new_size = this->num_elem+1;
		T* new_arr = new T[new_size];

		// copy old values over
		for(int i=0; i<idx; i++)
		{
			new_arr[i] = this->pArray[i];
		}
		new_arr[idx] = val;
		// copy old values over
		for(int i=idx+1; i<new_size; i++)
		{
			new_arr[i] = this->pArray[i-1];
		}
		
		// copy it over
		T* tmp = this->pArray;
		this->pArray = new_arr;

		// set the new size
		this->num_elem = new_size;

		// free the old array
		delete [] tmp;
		
	}

	// delete element at index 'idx' decreasing size by 1
	// Complexity: O(n)
	template <class T> 
	void DynArray<T>::erase(int idx)
	{
		if(idx < 0 || idx >= this->num_elem)
		{
			cerr << "Invalid index for erase at index: " << idx << endl;
			return;
		}

		// create a new array of size-1
		int new_size = this->num_elem-1;
		T* new_arr = new T[new_size];

		// copy old values over
		int new_i = 0;
		for(int i=0; i<this->num_elem; i++)
		{	
			// skip the element to be deleted
			if(i == idx)
				continue;
			else
			{
				new_arr[new_i] = this->pArray[i];
				new_i++;
			}
		}
		
		// copy it over
		T* tmp = this->pArray;
		this->pArray = new_arr;

		// set the new size
		this->num_elem = new_size;

		// free the old array
		delete [] tmp;
	}

	// returns the value at index 'idx' with boundary checking
	// Complexity: O(1)
	template <class T> 
	T DynArray<T>::at(int idx)
	{
		if(idx < 0 || idx > this->num_elem)
		{
			T ret;
			return ret;
		}

		return this->pArray[idx];

	}

	// return the number of elements in the array
	// Complexity: O(1)
	// - size is kept track of internally
	template <class T> 
	int DynArray<T>::size()
	{
		return this->num_elem;
	}



	// manually specify what datatypes are acceptable
	// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
	template class DynArray<int>;
	template class DynArray<float>;
	template class DynArray<double>;
	template class DynArray<string>;

	template class DynArray<kads::LinkedList<int> >;
	template class DynArray<kads::LinkedList<float> >;
	template class DynArray<kads::LinkedList<double> >;
	template class DynArray<kads::LinkedList<string> >;

	template class DynArray<kads::LinkedList<std::pair<string, int> > >;
	template class DynArray<kads::LinkedList<std::pair<string, float> > >;
	template class DynArray<kads::LinkedList<std::pair<string, double> > >;
	template class DynArray<kads::LinkedList<std::pair<string, string> > >;

}
