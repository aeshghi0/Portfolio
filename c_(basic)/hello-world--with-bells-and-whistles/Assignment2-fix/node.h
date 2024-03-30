
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node{
  public:
    int col;  //colomn indicator
    int row;  //row indicator
    Node *next; //pointer (to the next node)
    Node(); //default constructor, not used in this program
    Node(int, int);  //constructor to be used in this program
};

#endif