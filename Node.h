#pragma once

#include <iostream>
#include <string>
#include "TreeVector.h"
#include <list>

class Node {
public:
  Node(int key);
  void add(Node* newNode);
  int getKey();
  int balance();
  int depth();
  TreeVector print();
  void simpleSearch(int key, std::list<int> &chain);
  bool search(Node* root);
  Node* getLeft();
  Node* getRight();

private:
  int key;
  Node* left = nullptr;
  Node* right = nullptr;

};

