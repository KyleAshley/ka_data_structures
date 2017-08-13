#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 

#include "node.h"

using namespace std;

namespace kads
{
	template <class T> class LinkedList {
		
		public:

			// default ctor and dtor
			LinkedList();
			~LinkedList();

			// create a list with 'size' nodes all initialized with 'value'
			LinkedList(int size, T value);

			// inserts a new node with 'value' at the end of the list, 
			// - size of list is incremented
			void insert(T value);	
			// inserts a new node with 'value' at index 'idx'
			// - size of list is incremented
			void insert(T value, int idx);	

			// delete node at index 'idx', 
			// - size of list is decremented
			void erase(int idx);

			// returns the size of the list	
			int size();

			// prints each element in the list
			void print();

			

		private:
			Node<T>* head;	
			Node<T>* tail;
			int num_nodes;

	};


}


		
#endif



















