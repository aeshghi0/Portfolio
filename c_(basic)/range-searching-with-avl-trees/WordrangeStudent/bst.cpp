#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

int max(int a, int b){
  return a >= b? a : b;
}

// Default constructor sets head and tail to null
BST::BST(){
	root = NULL;
}

//Function to delete the Binary search tree from the start
void BST :: deleteBST()
{
  deleteBST(root);
}

//Recursive function that goes through all the nodes of the tree
void BST :: deleteBST(Node* root)
{
  if(root == NULL) // tree is already empty
    return; 
  deleteBST(root->left); // delete left subtree
  deleteBST(root->right); // delete right subtree
  delete(root); // delete node itself
}

void BST::insert(string str){
  Node *to_insert = new Node(str); // create a new Node with the value val
  if (root == NULL) // tree is currently empty
    root = to_insert; // make new node the root
  else
    root = insert(root,to_insert); // make call to recursive insert, starting from root
}

//Function to Insert a node to the AVL tree
Node* BST::insert(Node* root, Node* to_insert)
{
  if(root == NULL) // in general, this should not happen. We never call insert from a null tree
    return to_insert;
  if(to_insert->key.compare(root->key) < 0){ // inserted node has smaller (or equal) key, so go left to_insert->key <= start->key
    root->left = insert(root->left,to_insert);
    //to_insert->parent = root;
  }
  else if(to_insert->key.compare(root->key) > 0){ // inserted node has larger key, so go right
    root->right = insert(root->right,to_insert);
    //to_insert->parent = root;
  }
  else{
    return root;
  }

  root->height = 1 + max(height(root->left),height(root->right)); //updating the height of each node to balance the tree
  int balance_factor = get_balance_factor(root);  //get the balance factor from the root

  if(balance_factor > 1){
    if(to_insert->key.compare(root->left->key) < 0){  //str < left->key
      return right_rotate(root);
    }
    else if(to_insert->key.compare(root->left->key) > 0){
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }
  }
  else if(balance_factor < -1){ 
    if(to_insert->key.compare(root->right->key) > 0){ //str > right->key
      return left_rotate(root);
    }
    else if(to_insert->key.compare(root->right->key) < 0){
      root->right = right_rotate(root->right);
      return left_rotate(root);
      
    }
  }

  return root;
}

//Functio to look for a value in the list, if it exist
Node* BST::find(string str){

  return find(root, str); // call the recursive function starting at root
}

//Function to search for a node in the tree recursivly from the root, returns a pointer if the node found, if not returns a NULL
Node* BST::find(Node* root, string str){

  if(root == NULL || root->key.compare(str) == 0) // tree is empty or we found string
    return root;
  if(str.compare(root->key) < 0) // str is smaller, so go left 
    return find(root->left, str);
  else // str is larger, so go right
    return find(root->right, str);
}

//function that finds the number of strings that are lexographically in between the two strings str1 and str2
int BST::range(string str1, string str2){
  int count = 0;
  range_count(root, str1, str2, count);

  return count;
}

//Function that recursively computes the number of node entries with key between str1 and str2
void BST::range_count(Node *root, string str1, string str2, int &count){

  if(root == NULL){
    return;
  }
  if(str1.compare(root->key) <= 0 && str2.compare(root->key) >= 0){ //in range
    count = count + 1;

    if(root->left != NULL){
      if(str1.compare(root->left->key) <= 0){ //check the keft child key, is bigger than str1
        count = count + 1 + root->left->right_sub_size; //Add the size of right subtree to the count ,with the node itself;
        range_count(root->left->left,str1,str2,count);  //check the next left child of the left child
      }
      else{ //if left key was smaller than the str1
        range_count(root->left->right,str1,str2,count); //recursive call of the right child of the left child
      }
    }

    if(root->right != NULL){
      if(str2.compare(root->right->key) >= 0){
        count = count + 1 + root->right->left_sub_size;
        range_count(root->right->right,str1,str2,count);
      }
      else{
        range_count(root->right->left,str1,str2,count);
      }
    }
  }
  else if(str1.compare(root->key) > 0){ //node key is smaller than the first bound
    range_count(root->right,str1,str2,count);
  }
  else if(str2.compare(root->key) < 0){ //node key is bigger than the second bound
    range_count(root->left,str1,str2,count);
  }
}



//Function that returns the height of a node in the tree
int BST::height(Node *root){
  if(root == NULL){
    return 0;
  }
  return root->height;
}

//function that computes the balance factor of a node in the tree
int BST::get_balance_factor(Node *root){
  if(root == NULL){
    return 0;
  }
  return height(root->left) - height(root->right);
}

//Function to rotate left a subtree starting from its root
Node* BST::left_rotate(Node *root){
  Node *right = root->right;
  Node *left2 = right->left;


  right->left = root;
  root->right = left2;

  root->height = 1 + max(height(root->left),height(root->right));     //updating the previous root's height
  right->height = 1 + max(height(right->right),height(right->left));  //updating the new root's height

  return right;
}

//Function to rotate right a subtree starting from its root
Node* BST::right_rotate(Node *root){
  Node *left = root->left;
  Node *right2 = left->right;

  left->right = root;
  root->left = right2;

  root->height = 1 + max(height(root->left),height(root->right)); //updating the height of the previous root
  left->height = 1 + max(height(left->left),height(left->right)); //updating the height of the new root

  return left;
}


//function to set the sizes of each subtree and returns the size of the whole tree
int BST::set_sub_tree_sizes(){
  return get_size(root);
}


//Function that recursively counts the size of a tree
int BST::get_size(Node *root){
  if(root == NULL){
    return 0;
  }
  root->left_sub_size = get_size(root->left); //set the size of the left subtree of the root
  root->right_sub_size = get_size(root->right); //set the size of right subtree of the root

  return 1 + root->left_sub_size + root->right_sub_size;  //return the size of a node
}