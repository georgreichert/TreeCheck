#include "Tree.h"

void Tree::add(int key) {
	Node* temp = new Node(key);
	
	if (this->root != nullptr)
		this->root->add(temp);
	else
		this->root = temp;

	this->size++;
}

Node* Tree::getRoot() {
	return this->root;
}

void Tree::print() {
	TreeVector treeStats;
	if (this->root != nullptr) {
		treeStats = this->root->print();
		std::cout << "AVL: " << (treeStats.avl ? "yes" : "no") << std::endl;
		float avg = (float)treeStats.sum / this->size;
		std::cout << "min: " << treeStats.min << ", max: " << treeStats.max << ", avg: " << avg << std::endl;
	}
	else {
		std::cout << "Tree is empty";
	}
}

void Tree::simpleSearch(int key) {
	std::list<int> chain;
	if (this->root != nullptr) {
		this->root->simpleSearch(key, chain);
	}
	if (chain.empty()) {
		std::cout << key << " not found!" << std::endl;
	}
	else {
		std::cout << key << " found ";
		std::string path = "";
		for (int temp : chain) {
			path += std::to_string(temp) + ", ";
		}
		path = path.substr(0, path.length() - 2);
		std::cout << path << std::endl;
	}
}

void Tree::search(Tree& subtree) {
	if (subtree.getSize() == 1) {
		simpleSearch(subtree.getRoot()->getKey());
	}
	else if (this->root != nullptr) {
		bool found = this->root->search(subtree.getRoot());
		std::cout << (found ? "Subtree found" : "Subtree not found!") << std::endl;
	}
}

int Tree::getSize() {
	return this->size;
}