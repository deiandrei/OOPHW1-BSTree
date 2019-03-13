#include <iostream>

#include "Tree.h"

int main(int argc, char** argv) {
	Tree tree;
	tree.Insert(10);
	std::cin >> tree;
	tree = (8 + tree);
	tree = (28 + tree);
	tree = (38 + tree);
	tree.Insert(18);

	std::cout << tree << "\n";

	tree.Delete(11);

	tree.Print();

	tree.Delete(12);

	tree.Print();

	tree.PrintLeafs();

	std::cout << "\n\n\n" << tree.Height();
	return 0;
}
