#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

// node struct to hold data
class Node
{
  public:
    string key;
    Node *left, *right, *parent;
    int height; //stores the height of the node in the tree
    int left_sub_size;  //stores the size of the left sub tree
    int right_sub_size; //stores the size of the right sub tree

    Node(){ // default constructor
      left = right = parent = NULL; // setting everything to NULL
    }

    Node(string str){ // constructor that sets key to val
      key = str;
      left = right = parent = NULL; // setting everything to NULL
      height = 1;
      left_sub_size = right_sub_size = 0;
    }
};

class BST
{
	private:
		Node *root; // Stores root of tree
	public:
		BST(); // Default constructor sets root to null		
    void deleteBST(); // deletes every node to prevent memory leaks, and frees memory
    void deleteBST(Node* start); // deletes every Node in subtree rooted at startto prevent memory leaks.
    void insert(string); // insert int into list 
    Node* insert(Node*, Node*); // recursive version that inserts a node
    Node* find(string); // find int in tree, and return pointer to node with that int. If there are multiple copies, this only finds one copy
    Node* find(Node*, string); // recursive version that finds in a rooted subtree
    int range(string, string);  //count the number of strings lexographically between the two inputs and return as int
    void range_count(Node *, string, string, int &);  //function that recursively goes through the list to find the strings in between two strings
    int height(Node *); //functio that returns the height attribute of each node
    int get_balance_factor(Node *); //function that gets the balance factor of a node
    Node *left_rotate(Node *);
    Node *right_rotate(Node *);
    int set_sub_tree_sizes();
    int get_size(Node *);
};

#endif