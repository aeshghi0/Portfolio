#include "list.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

//default constructor
List::List(){
  
  head = NULL;
}

//function to free the memory of the list
void List::delete_list(){

  //if list is empty return
  if(head == NULL){
    return;
  }

  Node *curr = head;

  while(curr->next != NULL){
    Node *temp = curr->next;
    delete(curr);
    curr = temp;
  }

  delete(curr);
}

void List::delete_node(int col, int row){
  Node* prev = NULL;
  Node* curr = head;
  while(curr != NULL) // loop over list, starting from head
  {
    if(curr->col == col && curr->row == row) // we found Node with val, so break
      break; 
    //otherwise, proceed list
    prev = curr; // move prev by one Node
    curr = curr->next; // move curr by one Node
  }
  // at this point, curr points to Node with val. If curr is null, then val is not in the list.
  if (curr == NULL) // val not found
    return; 
  // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
  // Otherwise, we delete the Node after prev.
  if (prev == NULL){ // we need to delete head
    head = head->next; //update head
    delete(curr); // delete first
  } 
  else{ // we delete Node after prev. Note that both curr and prev are not NULL
    prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    curr->next = NULL;
    delete(curr);
  }
}

//returns a Node with specified row and colomn, if there is no such node, it returns NULL
Node *List::find(int col, int row){
  
  //if the list is empty, it returns NULL
  if(head == NULL){
    return NULL;
  }

  Node *curr = head;

  while(curr != NULL){
    if(curr->col == col && curr->row == row){
      return curr;
    }
    curr = curr->next;
  }

  return NULL;
}

//function to insert new node in the list with specified colomn and row
void List::insert(int col, int row){

  Node *new_node = new Node(col, row);  //creates a new node with colomn and row set
  new_node->next = head;  //pushes the node to the list
  head = new_node;  //updates the head
  return;
}

//function to sort the nodes in the list based on ascending colomn number
void List::sort(){

  Node *curr1 = head, *curr2 = head;
  Node *min;
  int temp_col, temp_row;

  while(curr1 != NULL){ //traverse the list
    curr2 = curr1;  //curr2 starts from curr1
    min = curr2;  //set the minimum to the first node we starting the traverse
    
    while(curr2 != NULL){ //traverse from curr2
      if(min->col > curr2->col){  //if the colomn of min node is bigger than colomn of curr2 node then update the min
        min = curr2;
      }
      curr2 = curr2->next;  //update curr2
    }
    //now swap
    temp_col = curr1->col;
    temp_row = curr1->row;
    curr1->col = min->col;
    curr1->row = min->row;
    min->col = temp_col;
    min->row = temp_row;

    curr1 = curr1->next;  //update to the next node
  }
}

//function that returns the length of the linked list as an integer
int List::list_length(){

  Node *curr = head;  //pointer to start from head of the list
  int count = 0;  //counter of nodes in the list
  while(curr != NULL){
    count++;  //increment the counter
    curr = curr->next;  //update the curr pointer
  }

  return count; //returns the length of the linked list (if the list is empty (head == NULL) returns zero)
}

//function to print the nodes of the list to the output file and screen
void List::print(ofstream &ofile){
  if(head == NULL){
    cout << "No solution";
    ofile << "No solution";
  }
  Node *curr = head;

  while(curr != NULL){
    cout << curr->col+1 << " " << curr->row+1 << " ";
    ofile << curr->col+1 << " " << curr->row+1 << " ";
    curr = curr->next;
  }
  cout << endl;
  ofile << endl;
}

//function to clear the elements of a linked list
void List::clear_list(){

  while(head != NULL){
    Node *curr = head;
    head = head->next;
    delete(curr);
  }

}

//function that checks if the list is empty
bool List::is_empty(){

  return head == NULL;
}