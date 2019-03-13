#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <algorithm>
#include <istream>

#include "Node.h"

class Tree {
	public:
		Tree();
		Tree(Node* root) { mRoot = root; }
		~Tree();

		void Insert(int value) { mRoot = InsertHelper(value, mRoot); }
		void Delete(int value) { mRoot = DeleteHelper(value, mRoot); }
		void Clear() { ClearHelper(mRoot); }
		
		int Height() { return HeightHelper(mRoot); }
		Node* FindMin(Node* node);
		Node* FindMax(Node* node);

		void Print() { PrintHelper(std::cout, mRoot); std::cout << "\n"; }
		void PrintLeafs() { PrintLeafsHelper(mRoot); std::cout << "\n"; }
	
	protected:
		Node* mRoot;

	////Recursive helpers
	protected:
		void ClearHelper(Node* node);
		int HeightHelper(Node* node);
		Node* InsertHelper(int value, Node* ref);
		Node* DeleteHelper(int value, Node* ref);
		void PrintHelper(std::ostream& stream, Node* node);
		void PrintLeafsHelper(Node* node);
	////
		
	public:
		friend std::istream& operator>>(std::istream& input, Tree& tree);
		friend std::ostream& operator<<(std::ostream& output, Tree& tree);
		Tree operator+(const int& value);
		friend Tree operator+(int value, Tree& tree);
};

#endif
