/******************************************************************/
// btree.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic BST
/******************************************************************/

#include "btree.h"

namespace kads
{

	template <class ValueType> 
	bTree<ValueType>::bTree()
	{
		this->head = NULL;
	}

	template <class ValueType> 
	bTree<ValueType>::~bTree()
	{

	}


	// inserts a new node to the tree
	template <class ValueType>
	bool bTree<ValueType>::insert(ValueType val, bNode<ValueType>* node)
	{
		bool success = false;
		if(node == NULL && node == this->head)
		{
			bNode<ValueType>* n = new bNode<ValueType>(val);
			this->head = n;
			return true;
		}
		
		if(node->value == val)
			return false;

		if(val < node->value)
		{
			if(node->left == NULL)
			{
				bNode<ValueType>* n = new bNode<ValueType>(val);
				node->left = n;
				return true;
			}
			else
			{
				success = this->insert(val, node->left);
			}
		}
		else if(val > node->value)
		{
			if(node->right == NULL)
			{
				bNode<ValueType>* n = new bNode<ValueType>(val);
				node->right = n;
				return true;
			}
			else
			{
				success = this->insert(val, node->right);
			}
		}
		return success;
	}


	// inserts a new node to the tree
	template <class ValueType>
	bool bTree<ValueType>::search(ValueType val, bNode<ValueType>* node)
	{
		bool found = false;
		if(node == NULL)
			return false;
		
		if(node->value == val)
			return true;

		else if(val < node->value)
			found = this->search(val, node->left);
		else if(val > node->value)
			found = this->search(val, node->right);

		return found;
	}

	template <class ValueType>
	void bTree<ValueType>::inOrderPrint(bNode<ValueType> *node)
	{
		if(node == NULL)
			return;

		this->inOrderPrint(node->left);
		cout << node->value << endl;
		this->inOrderPrint(node->right);
	}

	template <class ValueType>
	void bTree<ValueType>::preOrderPrint(bNode<ValueType> *node)
	{
		if(node == NULL)
			return;

		cout << node->value << endl;
		this->inOrderPrint(node->left);
		this->inOrderPrint(node->right);
	}

	template <class ValueType>
	void bTree<ValueType>::postOrderPrint(bNode<ValueType> *node)
	{
		if(node == NULL)
			return;

		this->inOrderPrint(node->left);
		this->inOrderPrint(node->right);
		cout << node->value << endl;
	}

	// returns the head of the tree
	template <class ValueType>
	bNode<ValueType>* bTree<ValueType>::getHead()
	{
		return this->head;
	}

	// returns the node with maximum value of the tree
	template <class ValueType>
	bNode<ValueType>* bTree<ValueType>::getMin()
	{
		bNode<ValueType>* n = this->head;
		if(n == NULL)
			return NULL;
		while(n->left != NULL)
		{
			n = n->left;
		}
		return n;
	}

	// returns the node with minimum value of the tree
	template <class ValueType>
	bNode<ValueType>* bTree<ValueType>::getMax()
	{
		bNode<ValueType>* n = this->head;
		if(n == NULL)
			return NULL;
		while(n->right != NULL)
		{
			n = n->right;
		}
		return n;
	}


	// some basic bTree types
	template class bTree<int>;
	template class bTree<float>;
	template class bTree<double>;
	template class bTree<string>;
	
}