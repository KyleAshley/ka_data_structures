#ifndef BNODE_H_
#define BNODE_H_

#include "stdio.h"
#include "stdlib.h"

#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

namespace kads
{
	template <class T> class bNode {
		
		public:
			bNode();
			~bNode();

			bNode(T val);

			T value;
			bNode* left;
			bNode* right;

		private:
			

	};
}

#endif