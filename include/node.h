#ifndef NODE_H_
#define NODE_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

namespace kads
{
	template <class T> class Node {
		
		public:
			Node();
			~Node();

			Node(T val);

			T value;
			Node* next;
			Node* prev;

		private:
			

	};
}

#endif