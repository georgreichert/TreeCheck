#pragma once

#include "Node.h"
#include <list>

class Tree {
public:
	void add(int key);
	Node* getRoot();
	void print();
	void search(Tree& subtree);
	int getSize();

private:
	Node* root = nullptr;
	int size = 0;
	void simpleSearch(int key);
};

