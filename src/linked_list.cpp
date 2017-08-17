/******************************************************************/
// linked_list.cpp
// Author: Kyle Ashley
// 
// Implementation of a basic doubly linked list
/******************************************************************/

#include "linked_list.h"

namespace kads
{

	// ctor
	template <class T> 
	LinkedList<T>::LinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
		this->num_nodes = 0;
	}

	// dtor
	// free the nodes in the list
	template <class T> 
	LinkedList<T>::~LinkedList()
	{
		
		Node<T>* curr = this->head;
		if(curr == NULL)
			return;

		Node<T>* next = curr->next;
		while(next != NULL)
		{
			next = curr->next;
			curr = next;
			delete curr;
		}

	}

	// initializes a new list of Nodes of size 'size' with values 0
	// Complexity: O(n)
	template <class T> 
	LinkedList<T>::LinkedList(int num_nodes, T val)
	{
		this->head = new Node<T>(val);
		this->head->prev = NULL;

		Node<T>* prev = this->head;

		for(int i=1; i<num_nodes-1; i++)
		{
			Node<T>* n = new Node<T>(val);
			prev->next = n;
			n->prev = prev;
			prev = n;
		}

		this->tail = new Node<T>(val);
		prev->next = this->tail;
		this->tail->prev = prev;
		this->tail->next = NULL;

		this->num_nodes = num_nodes;
	}

	// inserts a new node before 'idx'
	// Complexity: O(n)
	template <class T> 
	void LinkedList<T>::insert(T val, int idx)
	{
		// check if the index is valid
		if(idx > this->num_nodes || idx < 0)
		{
			cerr << "(!) Invalid index for insert at index: " << idx << endl; 
			return;
		}

		Node<T>* new_node = new Node<T>(val);

		// insert at head
		if(idx == 0)
		{
			this->head->prev = new_node;
			new_node->next = this->head;
			this->head = new_node;
		}
		// insert at tail
		else if(idx == this->num_nodes)
		{
			this->tail->next = new_node;
			new_node->prev = this->tail;
			this->tail = new_node;
		}
		//insert in the middle of the list
		else
		{
			// jump to the position
			int i = 0;
			Node<T>* curr = this->head;
			while(i < idx-1)
			{
				curr = curr->next;
				i++;
			}	
			new_node->prev = curr;
			new_node->next = curr->next;
			curr->next->prev = new_node;
			curr->next = new_node;
		}
		this->num_nodes++;
	}

	// inserts a new node at the end of the list
	// Complexity: O(1)
	template <class T> 
	void LinkedList<T>::push_back(T val)
	{
		Node<T>* new_node = new Node<T>(val);
		new_node->next = NULL;

		if(this->tail == NULL || this->head == NULL)
		{
			new_node->prev = NULL;
			this->head = new_node;
			this->tail = new_node;
		}
		else
		{
			new_node->prev = this->tail;
			this->tail->next = new_node;
			this->tail = new_node;
		}

		this->num_nodes++;
		return;		
	}

	// inserts a new node at the front of the list
	// Complexity: O(1)
	template <class T> 
	void LinkedList<T>::push_front(T val)
	{
		Node<T>* new_node = new Node<T>(val);
		new_node->next = this->head;
		new_node->prev = NULL;
		this->head->prev = new_node;
		this->head = new_node;
		this->num_nodes++;

		return;		
	}

	// erases node at the end of the list
	// Complexity: O(1)
	template <class T> 
	void LinkedList<T>::pop_back()
	{
		
		Node<T>* tmp = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		this->num_nodes--;

		delete tmp;
	}

	// erases node at the front of the list
	// Complexity: O(1)
	template <class T> 
	void LinkedList<T>::pop_front()
	{
		
		Node<T>* tmp = this->head;
		this->head = this->head->next;
		this->head->prev = NULL;
		this->num_nodes--;

		delete tmp;
	}

	// deletes node at position 'idx' of the list
	// Complexity: O(n)
	template <class T> 
	void LinkedList<T>::erase(int idx)
	{
		// check the index is valid
		if(idx >= this->num_nodes || idx < 0)
		{
			cerr << "(!) Invalid index for erase at index: " << idx << endl; 
			return;
		}

		int i = 0;
		Node<T>* curr = this->head;
		Node<T>* node; 			// node to be deleted

		// delete the head
		if(idx == 0)
		{	
			node = this->head;
			this->head = this->head->next;
			this->head->prev = NULL;
		}
		// delete the tail
		else if(idx == this->num_nodes-1)
		{
			node = this->tail;
			this->tail = this->tail->prev;
			this->tail->next = NULL;
		}
		// delete a middle node
		else
		{
			while(i < idx-1)
			{
				curr = curr->next;
				i++;
			}

			node = curr->next;
			curr->next = curr->next->next;
			curr->next->prev = curr;
		}

		delete node;
		this->num_nodes--;
		return;
		
	}

	// returns the value at index 
	// Complexity: O(n)
	template <class T> 
	T LinkedList<T>::at(int idx)
	{
		T defualtval;
		// check the index is valid
		if(idx >= this->num_nodes || idx < 0)
		{
			cerr << "(!) Invalid index at: " << idx << endl; 
			return defualtval;

		}

		else
		{
			int i = 0;
			Node<T>* curr = this->head;
			while(curr != NULL && i < idx)
			{
				curr = curr->next;
				i++;
			}
			return curr->value;
		}
	}


	// return the number of Nodes in the list
	// Complexity: O(1)
	// - size is kept track of internally
	template <class T> 
	int LinkedList<T>::size()
	{
		return this->num_nodes;
	}



	// manually specify what datatypes are acceptable
	template class LinkedList<int>;
	template class LinkedList<float>;
	template class LinkedList<double>;
	template class LinkedList<string>;

	template class LinkedList<std::pair<string, int> >;
	template class LinkedList<std::pair<string, float> >;
	template class LinkedList<std::pair<string, double> >;
	template class LinkedList<std::pair<string, string> >;

}
