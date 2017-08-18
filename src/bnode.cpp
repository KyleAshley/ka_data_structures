/******************************************************************/
// bnode.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic bnode for a binary tree
/******************************************************************/

#include "bnode.h"

namespace kads
{

	template <class T> 
	bNode<T>::bNode(T val)
	{
		this->value = val;
		this->left = NULL;
		this->right = NULL; 
	}

	template <class T> 
	bNode<T>::~bNode()
	{

	}


	// some basic bNode types
	template class bNode<int>;
	template class bNode<float>;
	template class bNode<double>;
	template class bNode<string>;
	
}