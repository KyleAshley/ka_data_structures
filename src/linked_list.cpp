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
	}

	// dtor
	template <class T> 
	LinkedList<T>::~LinkedList()
	{
		Node<T>* curr = this->head;
		Node<T>* next = curr->next;;
		while(next != NULL)
		{
			next = curr->next;
			curr = next;
			delete curr;
		}
	}

	// initializes a new list of Nodes of size 'size' with values 0
	template <class T> 
	LinkedList<T>::LinkedList(int size, T val)
	{
		this->head = new Node<T>(val);
		this->head->prev = NULL;

		Node<T>* prev = this->head;

		for(int i=0; i<size; i++)
		{
			Node<T>* n = new Node<T>(val);
			prev->next = n;
			n->prev = prev;
			prev = n;
		}

		this->tail = new Node<T>(val);
		tail->prev = prev;
		tail->next = NULL;
	}

	// return the number of Nodes in the list
	template <class T> 
	int LinkedList<T>::size()
	{
		int size = 1;
		Node<T>* curr = this->head;
		while(curr->next != NULL)
		{
			size++;
			curr = curr->next;
		}
		return size;
	}

	// prints the Node position and value for all Nodes in the list
	template <class T> 
	void LinkedList<T>::print()
	{
		int i = 0;
		Node<T>* curr = this->head;
		while(curr->next != NULL)
		{
			cout << "Node: " << i << " Value: " << curr->value << endl;
			curr = curr->next;
			i++;
		}

	}


	// manually specify what datatypes are acceptable
	template class LinkedList<int>;
	template class LinkedList<float>;
	template class LinkedList<double>;

}
