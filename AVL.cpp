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
  else if(x.key < (*parent)->data.key){                    
    avl_insert(&(*parent)->left, x, unbalanced); 
      if(*unbalanced){ 
        switch((*parent)->bf){ 
          case -1: (*parent)->bf = 0; 
           *unbalanced = FALSE; 
            break; 
          case 0:  (*parent)->bf = 1; 
            break; 
          case 1:  left_rotation(parent, unbalanced); 
      } 
    } 
  } 
  else if(x.key > (*parent)->data.key){ // symmetric with previous if-block 
  } 
  else { 
    *unbalanced = FALSE; 
    cout << “The key is already in the tree” << endl; 
  } 
} //end of avl_insert

void left_rotation(tree_node **parent, int *unbalanced) { 
 tree_node *grand_child, *child; 
 child = (*parent)->left; 
 if(child->bf == 1){ 
  // LL rotation 
  (*parent)->left = child->right; 
  child->right = *parent; 
  (*parent)->bf = 0; 
  (*parent) = child; 
 } 
 else { // LR rotation 
  grand_child = child->right; 
  child->right = grand_child->left; 
  grand_child->left = child; 
  (*parent)->left = grand_child->right; 
  grand_child->right = *parent; 
  switch(grand_child->bf){ 
   case 1: (*parent)->bf = -1; 
    child->bf = 0; break; 
   case 0: (*parent)->bf = child->bf = 0; 
    break; 
   case -1: (*parent)->bf = 0; 
    child->bf = 1; 
  } 
  *parent = grand_child; 
 } 
 (*parent)->bf = 0; 
 *unbalanced = FALSE;
}

/*Alg AVL_Delete(root, deleteKey, shorter) 
if tree is null can’t delete the node 
else if (deleteKey < root->key) 
  AVL_Delete(root->left, deleteKey, shorter) 
    if (shorter) RightBalance(root, shorter) 
else if (deleteKey > root->key) 
  AVL_Delete(root->right, deleteKey, shorter) 
  if (shorter) LeftBalance(root, shorter) 
else * node is found *
  if there is no left subtree 
    delete the node & attach its child pointer to its parent 
    shorter = true 
  else if there is no right subtree 
    delete the node & attach its child pointer to its parent 
    shorter = true 
  else /* two subtrees  
    find the largest node in left subtree : L_largest 
    copy L_largest to delete node AVL_Delete(root->left, L_largest, shorter) if (shorter) RightBalance(root, shorter) 

 
 
