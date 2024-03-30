
#ifndef LIST_H
#define LIST_H

#include "node.h"

class List{
  public:
    Node *head;
    List();   //default instructor
    void delete_list(); //free all memory of the list
    void delete_node(int, int);
    Node *find(int col, int row); //finds a node in the linked list with specified row and colomn
    void insert(int col, int row);  //inserts a new node to the list with specified row and colomn number
    void sort();  //sorts the node in the list based on accending of the colomn
    int list_length(); //returns the length of the linked list
    void clear_list();  //function to remove all of the elements of the linked list
    bool is_empty();  //Utility function that checks if the list is empty or not
    void print(ofstream &); //prints the list of the nodes to the output file and the terminal screen and output file

};

#endif