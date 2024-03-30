#include <iostream>
#include "bst.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{
  if (argc < 3){ // must provide two arguments as input
    throw std::invalid_argument("Usage: ./treewrapper <INPUT FILE> <OUTPUT FILE>"); // throw error
  }

  ifstream input; // stream for input file
  ofstream output; // stream for output file

  input.open(argv[1]); // open input file
  output.open(argv[2]); // open output file

  string command; // to store the next command and operation
  char *com, *valstr1,*valstr2, *op; // for using with strtok, strtol
  //int val = 0; // the value from the command
  //int val2 = 0; //second value from th command (if needed)

  BST rngBST; //initializing the linked list

  while(getline(input,command)){ // get next line of input, store as repeat
    if(command.length() == 0) // command is empty
      continue;
    com = strdup(command.c_str()); // annoying, first copy string into a "C-style" string
    op = strtok(com, " \t"); //tokenize command on whitespace, first token is operation

    valstr1 = strtok(NULL, " \t"); // next token is value, as string (check out documentation on strtok, to understand the parsing)
    if(valstr1 == NULL){ // first check if there is actually anything to convert into int
      continue;
    }
    valstr2 = strtok(NULL, " \t");  //getting the second input string of the command line (needed if the operation is 'r', NULL if its other operations)

    if(strcmp(op,"r") == 0){
      if(valstr2 == NULL){ // first check if there is actually anything to convert into int
        continue;
      }
      //TEST - trying to set the subtree sizes before looking for range queries
      int size = rngBST.set_sub_tree_sizes();
      if(size != 0){
        //TEST
        //cout << "Looking for range" << valstr1 << " " << valstr2 << endl;
        int count = rngBST.range(valstr1, valstr2);
        output << count << endl;
        //TEST
        //cout << count << endl;
      }
      else{
        continue;
      }
    }

    if(strcmp(op,"i") == 0){
      if(rngBST.find(valstr1) == NULL){ //checks if the word is not already in the list then adds that to the list
        //TEST
        //cout << "Insert" << endl;
        rngBST.insert(valstr1);
      }
    }
  }

  rngBST.deleteBST(); // delete the tree from memory
  input.close();
  output.close();

  return 0;
}