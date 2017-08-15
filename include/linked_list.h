// Implemetation of a doubly linked list
// Properties: 
// -	Constant time insertion and deletion at ends of the list
// -	Constant time iteration from begining or end of the list
// -	Bad random access time (O(n))


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
			// - Complexity: O(1)
			void push_back(T value);	

			// inserts a new node with 'value' at the front of the list, 
			// - size of list is incremented
			// - Complexity: O(1)
			void push_front(T value);

			// erases node at the end of the list, 
			// - size of list is decremented
			// - Complexity: O(1)
			void pop_back();

			// erases node at the front of the list, 
			// - size of list is decremented
			// - Complexity: O(1)
			void pop_front();

			// inserts a new node with 'value' at index 'idx'
			// - size of list is incremented
			// - Complexity: O(n)
			void insert(T value, int idx);	

			// delete node at index 'idx', 
			// - size of list is decremented
			// - Complexity: O(n)
			void erase(int idx);

			// erase a range of elements in the list
			// - Complexity: O(n)
			T at(int idx);

			// returns the size of the list	
			// - Complexity: O(1)
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



















