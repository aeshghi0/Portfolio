
#include "node.h"
#include <cstdlib>

using namespace std;

//default constructor for the class node
Node::Node(){
  col = row = 0;
  next = NULL;
}

//constructor to be used in this program
Node::Node(int colomn, int row_num){
  col = colomn;
  row = row_num;
  next = NULL;
}