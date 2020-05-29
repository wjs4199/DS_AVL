#include "AVL.h"

void avl_insert(tree_node **parent, element x, int *unbalanced) { 
if(!*parent){            //the node is empty 
  *unbalanced = TRUE; //the height is increased by insertion 
  *parent = new tree_node; 
  (*parent)->left = NULL; 
  (*parent)->right = NULL; 
  (*parent)->bf = 0; 
  (*parent)->data = x; 
} 
