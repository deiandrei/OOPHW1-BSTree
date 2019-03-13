#include "Tree.h"


Tree::Tree() {
	mRoot = nullptr;
}


Tree::~Tree() {
	
}

void Tree::ClearHelper(Node* target) {
	if (target == nullptr) return;
	
	ClearHelper(target->mLeft);
	ClearHelper(target->mRight);
	delete target;
}

Node* Tree::InsertHelper(int value, Node* ref) {
	if (ref == nullptr) ref = new Node(value);
	else if (value < ref->mData) ref->mLeft = InsertHelper(value, ref->mLeft);
	else if (value > ref->mData) ref->mRight = InsertHelper(value, ref->mRight);

	return ref;
}

int Tree::HeightHelper(Node* node) {
	if (node == nullptr) return 0;

	int leftHeight = HeightHelper(node->mLeft);
	int leftRight = HeightHelper(node->mRight);

	return (std::max(leftHeight, leftRight) + 1);
}

void Tree::PrintHelper(std::ostream& stream, Node* node) {
	if (node == nullptr) return;

	PrintHelper(stream, node->mLeft);
	stream << node->mData << " ";
	PrintHelper(stream, node->mRight);
}

void Tree::PrintLeafsHelper(Node* node) {
	if (node == nullptr) return;

	if (node->mLeft == nullptr && node->mRight == nullptr) std::cout << node->mData << " ";
	PrintLeafsHelper(node->mLeft);
	PrintLeafsHelper(node->mRight);
}

Node* Tree::FindMin(Node* node) {
	if (node == nullptr) return nullptr;
	else if (node->mLeft == nullptr) return node;
	else return FindMin(node->mLeft);
}

Node* Tree::FindMax(Node* node) {
	if (node == nullptr) return nullptr;
	else if (node->mRight) return node;
	else return FindMax(node->mRight);
}

Node* Tree::DeleteHelper(int value, Node* ref) {
	if (ref == nullptr) return nullptr;
	
	Node* tempnode;
	if (value < ref->mData) ref->mLeft = DeleteHelper(value, ref->mLeft);
	else if (value > ref->mData) ref->mRight = DeleteHelper(value, ref->mRight);
	else if (value == ref->mData) {
		if (ref->mLeft != nullptr && ref->mRight != nullptr) {
			tempnode = FindMin(ref->mRight);
			ref->mData = tempnode->mData;
			ref->mRight = DeleteHelper(ref->mData, ref->mRight);
		}
		else {
			tempnode = ref;
			if (ref->mLeft == nullptr) ref = ref->mRight;
			else if (ref->mRight == nullptr) ref = ref->mLeft;
			delete tempnode;
		}
	}

	return ref;
}

std::istream& operator>>(std::istream& input, Tree& tree) {
	int value;
	input >> value;
	tree.Insert(value);
	return input;
}

std::ostream& operator<<(std::ostream& output, Tree& tree) {
	tree.PrintHelper(output, tree.mRoot);
	return output;
}

Tree Tree::operator+(const int& value) {
	Insert(value);
	return *this;
}

Tree operator+(int value, Tree& tree) {
	tree.Insert(value);
	return tree;
}
