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


	// deletes a node with a given value from the tree
	// returns true on success, false otherwise
	template <class ValueType>
	bool bTree<ValueType>::erase(ValueType val, bNode<ValueType>* node)
	{
		bool foundleft = false;
		bool foundright = false;
		bool foundroot = false;

		if(node == NULL)
			return false;
		
		// base case for non-root nodes
		if(node->value == val && node != this->head)
			return true;
		// recursively search for the node
		else if(val < node->value)
			foundleft = this->erase(val, node->left);
		else if(val > node->value)
			foundright = this->erase(val, node->right);
		// returns true only if the node to delete is the head of the tree
		else if(node == this->head)
			foundroot = true;

		bNode<ValueType>* n_del;
		if(foundleft)				// node to delete is left child of the current node
			n_del = node->left;
		else if(foundright)			// node to delete is right child of the current node
			n_del = node->right;	
		else if(foundroot)			// node to delete is the root of the tree
			n_del = node;

		if(foundleft || foundright || foundroot)
		{

			// no children
			if(n_del->left == NULL && n_del->right == NULL)
			{
				cout << "no children" << endl;
				if(foundleft)
					node->left = NULL;
				else if(foundright)
					node->right = NULL;
				else
					this->head = NULL;
				delete n_del;
			}
			// two childrem
			else if(n_del->left != NULL && n_del->right != NULL)
			{
				cout << "two children" << endl;
				// get the min of the tree rooted in the right subtree
				bNode<ValueType>* n_min = n_del->right;
				bNode<ValueType>* n_parent = n_del->right;
				if(n_min->left == NULL)
				{
					n_del->right = NULL;
				}
				else
				{
					while(n_min->left != NULL)
					{
						n_parent = n_min;
						n_min = n_min->left;
					}
					
					n_parent->left = NULL;
				}
				// assign the value to the node to be deleted
				n_del->value = n_min->value;
				// delete the, now duplicate, minimum node
				delete n_min;
			}

			// one child
			else
			{	
				// reasign the left node to the existing child
				if(foundleft)
				{
					cout << "left children" << endl;
					if(n_del->left != NULL)
						node->left = n_del->left;
					else if(n_del->right != NULL)
						node->left = n_del->right;
					delete n_del;
				}
				if(foundright)
				{
					cout << "right children" << endl;
					if(n_del->left != NULL)
						node->right = n_del->left;
					else if(n_del->right != NULL)
						node->right = n_del->right;
					delete n_del;
				}
			}
		}

		return false;
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

	// returns the node with maximum value of the tree rooted at 'node'
	template <class ValueType>
	bNode<ValueType>* bTree<ValueType>::getMin(bNode<ValueType>* node)
	{
		bNode<ValueType>* n = node;
		if(n == NULL)
			return NULL;
		while(n->left != NULL)
		{
			n = n->left;
		}
		return n;
	}

	// returns the node with minimum value of the tree rooted at 'node'
	template <class ValueType>
	bNode<ValueType>* bTree<ValueType>::getMax(bNode<ValueType>* node)
	{
		bNode<ValueType>* n = node;
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