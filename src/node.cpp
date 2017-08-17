/******************************************************************/
// node.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic node for a doubly linked list
/******************************************************************/

#include "node.h"

namespace kads
{

	template <class T> 
	Node<T>::Node(T val)
	{
		this->value = val;
		this->next = NULL;
		this->prev = NULL; 
	}

	template <class T> 
	Node<T>::~Node()
	{

	}


	// some basic Node types
	template class Node<int>;
	template class Node<float>;
	template class Node<double>;
	template class Node<string>;

	// pairwise node types
	template class Node<std::pair<string, int> >;
	template class Node<std::pair<string, float> >;
	template class Node<std::pair<string, double> >;
	template class Node<std::pair<string, string> >;
	
}