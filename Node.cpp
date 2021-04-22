#include "Node.h"

#include <iostream>

Node::Node(int key) {
	this->key = key;
}

void Node::add(Node* newNode) {
	if (newNode->getKey() > this->key) {
		if (this->right != nullptr)
			this->right->add(newNode);
		else
			this->right = newNode;
	}
	else if (newNode->getKey() < this->key) {
		if (this->left != nullptr)
			this->left->add(newNode);
		else
			this->left = newNode;
	}
	else {
		delete newNode;
	}
}

int Node::getKey() {
	return this->key;
}

int Node::balance() {
	int left = this->left != nullptr ? this->left->depth() : 0;
	int right = this->right != nullptr ? this->right->depth() : 0;
	return right - left;
}

int Node::depth() {
	int right = this->right == nullptr ? 0 : this->right->depth();
	int left = this->left == nullptr ? 0 : this->left->depth();
	return (left > right ? left : right) + 1;
}

TreeVector Node::print() {
	TreeVector ret = { this->key, this->key, this->key, true};
	if (this->right != nullptr) {
		TreeVector right = this->right->print();
		ret = { ret.min < right.min ? ret.min : right.min,
				ret.max > right.max ? ret.max : right.max,
				ret.sum + right.sum,
				right.avl ? ret.avl : right.avl };
	}

	if (this->left != nullptr) {
		TreeVector left = this->left->print();
		ret = { ret.min < left.min ? ret.min : left.min,
				ret.max > left.max ? ret.max : left.max,
				ret.sum + left.sum,
				left.avl ? ret.avl : left.avl };
	}

	int balance = this->balance();
	ret.avl = (balance <= 1 && balance >= -1) ? ret.avl : false;
	std::cout << "bal(" << this->key << ") = " << balance << ((balance <= 1 && balance >= -1) ? "" : " (AVL violation!)") << std::endl;
	return ret;
}

void Node::simpleSearch(int key, std::list<int> &chain) {
	if (this->key == key) {
		chain.push_front(key);
		return;
	} else if (key < this->key && this->left != nullptr) {
		this->left->simpleSearch(key, chain);
	}
	else if (key > this->key && this->right != nullptr) {
		this->right->simpleSearch(key, chain);
	}
	if (!chain.empty()) {
		chain.push_front(this->key);
	}
}

bool Node::search(Node* root) {
	if (root == nullptr) {
		return true;
	}
	bool ret = false;
	if (this->key == root->key) {
		if (root->getLeft() == nullptr) {
			ret = true;
		}
		else {
			ret = this->left != nullptr ? this->left->search(root->getLeft()) : false;
		}
		if (root->getRight() != nullptr) {
			ret = this->right != nullptr ? this->right->search(root->getRight()) : false;
		}
	}
	else if (root->getKey() < this->key) {
		if (this->left != nullptr) {
			return this->left->search(root);
		}
		else {
			return false;
		}
	}
	else if (root->getKey() > this->key) {
		if (this->right != nullptr) {
			return this->right->search(root);
		}
		else {
			return false;
		}
	}
	return ret;
}

Node* Node::getLeft() {
	return this->left;
}

Node* Node::getRight() {
	return this->right;
}
