# TreeCheck
Simple console application to check if a binary search tree built from a text file is balanced, and if it contains a given subtree.
Made in collaboration with Martin Bitzan.  
  
Example use:  
  
treecheck trees/tree.txt  
Checks if the tree specified in tree.txt is balanced, and lists minimum, maximum and average key value.  
  
treecheck trees/tree.txt trees/subtree.txt
Checks if the tree specified in subtree.txt is a subtree of tree.txt (ignoring intermediate keys, so it returns "possible" subtrees as true too)
