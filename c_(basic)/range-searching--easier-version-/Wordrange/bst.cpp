#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

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
    insert(root,to_insert); // make call to recursive insert, starting from root
}

void BST::insert(Node* root, Node* to_insert)
{
  if(root == NULL) // in general, this should not happen. We never call insert from a null tree
    return;
  if(to_insert->key.compare(root->key) <= 0){ // inserted node has smaller (or equal) key, so go left to_insert->key <= start->key
    if(root->left == NULL){
      root->left = to_insert; // make this node the left child
      to_insert->parent = root; // set the parent pointer
      return;
    }
    else // need to make recursive call
    {
      insert(root->left, to_insert);
      return;
    }
  }
  else{ // inserted node has larger key, so go right
    if(root->right == NULL){
      root->right = to_insert; // make this node the right child
      to_insert->parent = root; // set the parent pointer
      return;
    }
    else{ // need to make recursive call
      insert(root->right, to_insert);
      return;
    }
  }
}

//Functio to look for a value in the list, if it exist
//CHANGE TO STRINGS
Node* BST::find(string str){

  return find(root, str); // call the recursive function starting at root
}

//Function to search for a node in the tree recursivly from the root, returns a pointer if the node found, if not returns a NULL
//CHANGE TO STRINGS
Node* BST::find(Node* root, string str){

  if(root == NULL || root->key.compare(str) == 0) // tree is empty or we found string
    return root;
  if(str.compare(root->key) < 0) // str is smaller, so go left 
    return find(root->left, str);
  else // val is larger, so go right
    return find(root->right, str);
}

//function that finds the number of strings that are lexographically in between the two strings str1 and str2
int BST::range(string str1, string str2){
  int count = 0;
  range_count(root, str1, str2, count);

  return count;
}

void BST::range_count(Node *root, string str1, string str2, int &count){
  if(root == NULL){
    return;
  }
  range_count(root->right, str1, str2, count);
  range_count(root->left, str1, str2, count);

  if(root->key.compare(str1) >= 0 && root->key.compare(str2) <= 0){
    count += 1;
  }
}