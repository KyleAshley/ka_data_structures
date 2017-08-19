// Implemetation of a BST
// Properties:  
// - Insert and search in O(lgn) time
// - 

#ifndef BTREE_H_
#define BTREE_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h> 

#include "bnode.h"

using namespace std;



namespace kads
{
	// basic BST
	// - this class was implemented as an exercise to understand 
	//   BST datastructures and associated algorithms
	template <class ValueType> class bTree {
		
		public:
			bTree();
			~bTree();

			// - inserts a new node to the tree rooted at 'node'
			// - returns true on success, false otherwise
			bool insert(ValueType val, bNode<ValueType> *node);

			// - deletes a node with a given value from the tree
			// - returns true on success, false otherwise
			bool erase(ValueType val, bNode<ValueType> *node);

			// - searches for node with 'val' to the tree rooted at 'node'
			// - returns true if found, false otherwise
			bool search(ValueType val, bNode<ValueType> *node);

			// prints the values of each node using in-order traversal
			void inOrderPrint(bNode<ValueType> *node);

			// prints the values of each node using in-order traversal
			void postOrderPrint(bNode<ValueType> *node);

			// prints the values of each node using in-order traversal
			void preOrderPrint(bNode<ValueType> *node);

			// returns the head of the tree
			// Complexity: O(1)
			bNode<ValueType>* getHead();

			// returns the minimum value in the tree 
			// Complexity: O(n)
			bNode<ValueType>* getMin(bNode<ValueType>*);

			// returns the maximum value in the tree 
			// Complexity: O(n)
			bNode<ValueType>* getMax(bNode<ValueType>*);

		private:
			bNode<ValueType>* head;

	};

}

#endif