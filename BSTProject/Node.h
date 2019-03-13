#ifndef NODE_H_
#define NODE_H_

class Tree;

class Node {
	public:
		Node(int value = 0);

	private:
		Node *mLeft, *mRight;
		int mData;
		
		friend class Tree;
};

#include "Tree.h"

#endif
