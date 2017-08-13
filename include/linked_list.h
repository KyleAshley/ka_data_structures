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

			LinkedList(int size, T value);

			void print();
			int size();

			Node<T>* head;
			Node<T>* tail;

		private:


	};


}


		
#endif



















